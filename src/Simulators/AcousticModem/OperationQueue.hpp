//***************************************************************************
// Copyright 2007-2019 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Faculdade de Engenharia da             *
// Universidade do Porto. For licensing terms, conditions, and further      *
// information contact lsts@fe.up.pt.                                       *
//                                                                          *
// Modified European Union Public Licence - EUPL v.1.1 Usage                *
// Alternatively, this file may be used under the terms of the Modified     *
// EUPL, Version 1.1 only (the "Licence"), appearing in the file LICENCE.md *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// https://github.com/LSTS/dune/blob/master/LICENCE.md and                  *
// http://ec.europa.eu/idabc/eupl.html.                                     *
//***************************************************************************
// Author: Luis Venancio                                                    *
//***************************************************************************

#ifndef SIMULATORS_ACOUSTICMODEM_OPERATIONQUEUE_HPP_INCLUDED_
#define SIMULATORS_ACOUSTICMODEM_OPERATIONQUEUE_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <string>

// DUNE headers.
#include <DUNE/DUNE.hpp>

#define RANGE(x, low, high) (x >= low && x <= high)

namespace Simulators
{
  namespace AcousticModem
  {
    using DUNE_NAMESPACES;
    
    //! Structure holding transmission/reception operation
    //! parameters.
    struct Operation
    {
      Operation(const Operation &op):
      is_tx(op.is_tx),
      start_time(op.start_time),
      end_time(op.end_time),
      msg(op.msg),
      deliver(true)
      {}

      Operation(const bool &a_is_tx, 
                const double a_start_time, 
                const SimAcousticMessage &a_msg):
      is_tx(a_is_tx),
      start_time(a_start_time),
      end_time(a_start_time + a_msg.txtime),
      msg(a_msg),
      deliver(true)
      {}

      Operation():
      deliver(true)
      {}

      Operation&
      operator=(const Operation op)
      {
        is_tx       = op.is_tx;
        start_time  = op.start_time;
        end_time    = op.end_time;
        msg         = op.msg;
        deliver     = op.deliver;

        return *this;
      }

      //! Transmission flag.
      bool is_tx;
      //! Time to start operation.
      double start_time;
      //! Time to end operation.
      double end_time;
      //! Message to handle.
      IMC::SimAcousticMessage msg;
      //! Deliver flag
      bool deliver;
    };

    class OperationQueue
    {
    public:
      //! Constructor.
      OperationQueue()
      {}

      //! Destructor.
      ~OperationQueue(void)
      {}

      //! Add an operation to queue.
      //! @param[in] a_op operation to add to queue.
      void
      add(Operation a_op)
      {
        checkCollision(&a_op);
        m_queue.push_back(a_op);
      }

      //! Check message queue for a valid delivery time.
      //! @param[in] active_op pointer to retrieve a viable operation.
      std::unique_ptr<Operation>
      check()
      {
        std::unique_ptr<Operation> active_op{nullptr};

        if (m_queue.empty())
          return active_op;

        auto op = m_queue.begin();
        while(op != m_queue.end())
        {
          // Operation starts
          if (op->start_time <= Clock::getSinceEpoch())
          {
            // Set medium as busy for the duration of 
            // the message transmission/delivery
            m_medium_busy.setTop(op->msg.txtime);

            // Set modem as busy for the duration of 
            // the message transmission/delivery
            if (op->deliver)
              m_modem_busy.setTop(op->msg.txtime);
          }

          // Operation ends
          if (op->end_time <= Clock::getSinceEpoch())
          {
            if (op->deliver)
              active_op = std::make_unique<Operation>(*op);

            m_queue.erase(op);
          }
          else
          {
            ++op;
          }
        }

        return active_op;
      }

      //! Check if modem is busy
      //! @return true if an operation is being performed, false otherwise.
      bool 
      isBusy()
      {
        return !m_modem_busy.overflow();
      }

      //! Check if medium is busy
      //! @return true if the medium is busy.
      bool 
      isMediumBusy()
      {
        return !m_medium_busy.overflow();
      }
      
    private:
      //! Operation queue (operations in medium)
      typedef std::vector<Operation> OpQueue;
      OpQueue m_queue;
      //! Timer for busy medium
      Time::Counter<double> m_medium_busy;
      //! Timer for busy modem
      Time::Counter<double> m_modem_busy;

      
      //! Message collision logic goes here.
      //! @param[in] new_op new operation candidate
      //! @return true if no collision is detected
      void
      checkCollision(Operation* new_op)
      {
        if (m_queue.empty())
          return;

        for(auto op = m_queue.begin(); op != m_queue.end(); ++op)
        {
          if (RANGE(new_op->start_time, op->start_time, op->end_time) ||
              RANGE(new_op->end_time, op->start_time, op->end_time))
          {
            new_op->deliver = false;
            op->deliver     = false;
          }
        }
      }
    };
  }
}

#endif
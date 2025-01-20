//***************************************************************************
// Copyright 2007-2023 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Pedro Calado                                                     *
//***************************************************************************

// ISO C++ 98 headers.
#include <cmath>

// DUNE headers.
#include <DUNE/DUNE.hpp>

// #include "AcousticProtocol.hpp"

namespace Maneuver
{
  namespace VehicleFormation
  {
    namespace Leader
    {
      using DUNE_NAMESPACES;

      struct Arguments
      {

      };

      struct Task: public DUNE::Maneuvers::SwarmLeader
      {
        //! last state update
        IMC::EstimatedState m_estate;
        //! Number of current waypoint number
        int m_curr;
        //! Previously assigned waypoint
        TPoint m_prev;
        //! Task arguments
        Arguments m_args;
        //! Swarm acoustic protocol
        Swarm::AcousticProtocol m_aprot;
        //! Acknowledgement timer
        Time::Counter<double> m_ack_timer;
        //! Received ack id
        uint16_t m_rcv_ack_id;
        //! Report position timer
        Time::Counter<double> m_pos_report_timer;

        Task(const std::string& name, DUNE::Tasks::Context& ctx):
          SwarmLeader(name, ctx),
          m_aprot(this),
          m_rcv_ack_id(IMC::AddressResolver::invalid())
        {
          bind<IMC::UamRxFrame>(this, true);
        }

        void
        onUpdateParameters(void)
        {
          SwarmLeader::onUpdateParameters();
        }

        //! On resource initialization
        void
        onResourceInitialization(void)
        {
          Maneuver::onResourceInitialization();
          m_ack_timer.setTop(10);
          m_pos_report_timer.setTop(10);
        }

        void
        consume(const IMC::UamRxFrame * msg)
        {
          if (!m_aprot.validate(msg))
            return;

          switch (msg->data[1])
          {
            case CODE_ACK:
              recvAck(msg);
              break;
            default:
              debug("Invalid acoustic code: %u", msg->data[1]);
              break;
          }
        }

        void
        recvAck(const IMC::UamRxFrame* msg)
        {
          m_rcv_ack_id = resolveSystemName(msg->sys_src);
        }

        //! Close matlab logged vectors
        void
        onReset(void)
        {
        }

        void
        sendNextPoint(const TPoint& next)
        {
          double lat;
          double lon;
          fromLocalCoordinates(next.x, next.y, &lat, &lon);
          m_aprot.sendNext("broadcast", bearing(m_curr), lat, lon);
        }

        void
        onInit(const IMC::VehicleFormation* maneuver)
        {
          (void)maneuver;

          //Initiate m_prev as first waypoint
          m_prev = point(0, -1);

          // Initiate waypoint counter at zero
          m_curr = 0;

          // Send participant setups and wait for acknowledgement
          setupParticipants();

          // Send participants next point
          sendNextPoint(m_prev);

          // Send initial DesiredPath
          IMC::DesiredPath path = getDesiredPath();
          dispatch(path);

          ++m_curr;

          m_pos_report_timer.reset();
        }

        void
        setupParticipants()
        {
          for(size_t i = 0; i < participants(); i++)
          {
            Participant part = participant(i);

            int retries = 0;
            while (retries < 5)
            {
              m_aprot.sendSetup(resolveSystemId(part.vid), i, part.x, part.y, part.z);
              if (waitAck(part.vid))
                break;
              else
                retries++;
            }
          }
        }

        bool
        waitAck(uint16_t sys_id)
        {
          m_rcv_ack_id = IMC::AddressResolver::invalid();
          m_ack_timer.reset();
          while (!m_ack_timer.overflow())
          {
            waitForMessages(1.0);

            if (sys_id == m_rcv_ack_id)
            {
               m_rcv_ack_id = IMC::AddressResolver::invalid();
               return true;
            }
          }

          m_rcv_ack_id = IMC::AddressResolver::invalid();
          return false;
        }

        void
        step(const IMC::EstimatedState& estate)
        {
          m_estate = estate;

          if (m_curr <= 0)
            return;
          
          if (m_pos_report_timer.overflow())
          {
            double lat;
            double lon;
            fromLocalCoordinates(m_estate.x, m_estate.y, &lat, &lon);
            m_aprot.sendPos("broadcast", m_estate.psi, lat, lon);
            m_pos_report_timer.reset();
          }
        }

        void
        onPathCompletion(void)
        {
          TPoint next;

          // If it is the first time the function on Path Completion is being called
          if (m_curr == 0)
          {
            m_prev.x = m_estate.x;
            m_prev.y = m_estate.y;
            m_prev.z = m_estate.depth;
            m_prev.t = 0.0;
          }

          // if the current waypoint is the last, then all is done
          if ((size_t)m_curr == trajectory_points())
          {
            signalCompletion(); // All done
            return; // All done
          }

          // the trajectory given to the present vehicle will always be the original one
          // offset by a certain amount m_delta, updated when a new message is received
          // next.x = point(m_curr,formation_index()).x + m_delta(0);
          // next.y = point(m_curr,formation_index()).y + m_delta(1);
          next = point(m_curr, -1);

          // Send next point to participants
          sendNextPoint(next);

          // throw a leg of TPoints to be followed by the vehicle
          desiredPath(m_prev, next);

          ++m_curr;
          m_prev = next;
        } // End of function onPathCompletion
      };
    }
  }
}

DUNE_TASK

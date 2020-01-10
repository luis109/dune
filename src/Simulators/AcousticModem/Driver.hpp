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

#ifndef SIMULATORS_ACOUSTICMODEM_DRIVER_HPP_INCLUDED_
#define SIMULATORS_ACOUSTICMODEM_DRIVER_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <string>

// DUNE headers.
#include <DUNE/DUNE.hpp>

#include "OperationQueue.hpp"

namespace Simulators
{
  namespace AcousticModem
  {
    using DUNE_NAMESPACES;

    //! Sound speed (m/s).
    static const double c_sound_speed = 1500.0;
    //! Absolute maximum transmission range.
    static const double c_max_range = 3000.0;
    //! Maximum time an operation remains in queue after start_time
    static const double c_operation_lifetime = 5.0;

    struct DriverArguments
    {
      //! Multicast Address.
      Address udp_maddr;
      //! UDP port.
      uint16_t udp_port;
      //! Modem type.
      std::string modem_type;
      //! Promiscuous
      bool promiscuous;
      //! Trasmission speed.
      double tx_speed;
      //! Standard deviation for distance probability.
      float dst_peak_width;
      //! Standard deviation for data size probability.
      float dsize_peak_width;
      //! PRNG type.
      std::string prng_type;
      //! PRNG seed.
      int prng_seed;
    };

    class Driver: public Concurrency::Thread
    {
    public:
      //! Constructor.
      Driver(DriverArguments* a_args, IMC::SimulatedState* a_sstate, Tasks::Task* a_task):
      m_task(a_task),
      m_args(a_args),
      m_sstate(a_sstate),
      m_sock(NULL),
      m_prng(NULL)
      {
        // Initialize UDP socket in multicast
        m_sock = new DUNE::Network::UDPSocket();
        m_sock->setMulticastTTL(1);
        m_sock->setMulticastLoop(true);
        m_sock->joinMulticastGroup(m_args->udp_maddr);
        m_sock->bind(m_args->udp_port);

        // Initialize random number generator
        m_prng = Random::Factory::create(m_args->prng_type, m_args->prng_seed);
      }

      //! Destructor.
      ~Driver(void)
      {
        if (m_sock)
          Memory::clear(m_sock);

        Memory::clear(m_prng);
      }

      //! Set current operation to transmission operation.
      //! @param[in] msg message to transmit.
      void
      transmit(const IMC::SimAcousticMessage a_msg)
      {
        m_queue.add(Operation(true, a_msg.getTimeStamp(), a_msg));
      }

      //! Overload of transmission for UamTxFrame.
      //! @param[in] msg message to transmit.
      void
      transmit(const IMC::UamTxFrame a_msg)
      {
        IMC::SimAcousticMessage sim_acoustic_msg;
        // Construct simulated acoustic message metadata
        Coordinates::toWGS84(*m_sstate, sim_acoustic_msg.lat, 
                                        sim_acoustic_msg.lon,
                                        sim_acoustic_msg.height);
        sim_acoustic_msg.modem_type = m_args->modem_type;
        sim_acoustic_msg.txtime     = (double)a_msg.data.size() * 8 / m_args->tx_speed;
        sim_acoustic_msg.sys_src    = m_task->getSystemName();

        // Copy UamTxFrame data
        sim_acoustic_msg.seq        = a_msg.seq;
        sim_acoustic_msg.sys_dst    = a_msg.sys_dst;
        sim_acoustic_msg.flags      = a_msg.flags;
        sim_acoustic_msg.data       = a_msg.data;

        // Set header
        sim_acoustic_msg.setSource(m_task->getSystemId());
        sim_acoustic_msg.setTimeStamp();

        transmit(sim_acoustic_msg);
      }

      //! Modem is busy if there is a valid current operation.
      //! @return true if modem is busy.
      bool
      isBusy()
      {
        return m_queue.isBusy();
      }

      //! Distance to source vehicle.
      //! @param[in] msg current vehicle state.
      double
      distance(const IMC::SimAcousticMessage* src_state)
      {
        double lat, lon;
        float hae;
        Coordinates::toWGS84(*m_sstate, lat, lon, hae);

        return WGS84::distance(lat, lon, hae,
                              src_state->lat, src_state->lon, src_state->height);
      }

    private:
      //! Simulator task
      Tasks::Task* m_task;
      //! Driver arguments
      DriverArguments* m_args;
      //! Vehicle simulated state
      IMC::SimulatedState* m_sstate;
      //! UDP socket.
      UDPSocket* m_sock;
      //! UDP message buffer.
      uint8_t m_buf[1024];
      //! PRNG handle.
      Random::Generator* m_prng; 
      //! Operation queue.
      OperationQueue m_queue;
      //! Active operation
      std::unique_ptr<Operation> m_operation;

      //! Transmit message over UDP.
      //! @param[in] message to transmit.
      void
      share(const IMC::Message* msg)
      {
        int n = msg->getSerializationSize();
        IMC::Packet::serialize(msg, m_buf, n);
        m_sock->write(m_buf, n, m_args->udp_maddr, m_args->udp_port);
        
        debugMessage("Message sent: ", msg);
      }

      //! Check UDP socket for incoming message.
      void
      checkIncomingData()
      {
        Address dummy;

        try
        {
          if (Poll::poll(*m_sock, 0.01))
          {
            size_t n = m_sock->read(m_buf, sizeof(m_buf), &dummy);
            IMC::Message* msg = IMC::Packet::deserialize(m_buf, n);

            if (msg->getId() == DUNE_IMC_SIMACOUSTICMESSAGE)
            {
              IMC::SimAcousticMessage* amsg = static_cast<IMC::SimAcousticMessage*>(msg);
              if (parse(amsg))
                receive(*amsg);

              debugMessage("Message received: ", amsg);
            }
            else
            {
              m_task->err(DTR("Unexpected simulation message: %s"), msg->getName());
            }
            delete msg;
          }
        }
        catch(std::runtime_error& e)
        {
          m_task->err(DTR("Read error: %s"), e.what());
        }
      }

      //! Compute delivery time and add operation to queue.
      //! @param[in] a_msg message to add to queue.
      void
      receive(IMC::SimAcousticMessage a_msg)
      {
        double start_time = a_msg.getTimeStamp()
                            + distance(&a_msg)/c_sound_speed;

        m_queue.add(Operation(false, start_time, a_msg));
      }

      //! Check if received message should be added to queue.
      //! @param[in] amsg message to add to queue.
      //! @return true if message is parsed.
      bool
      parse(const IMC::SimAcousticMessage* a_msg)
      {
        bool check;

        // Check if it is from ourselfs
        check = a_msg->sys_src != m_task->getSystemName();

        // If not promiscuous check if we are the destination
        if (!m_args->promiscuous)
        {
          // Specific destination
          // or Broadcast 
          check &= (a_msg->sys_dst == m_task->getSystemName()) | (a_msg->sys_dst == "broadcast");
        }

        // Isolate by modem type
        check &= a_msg->modem_type == m_args->modem_type;

        // Simulate data loss
        double dist = distance(a_msg);
        check &= deliverySucceeds(dist, a_msg->data.size());

        return check;
      }

      //! Simulate random successful delivery 
      //! based on gaussian model of distance and data size.
      //! @param[in] distance distance to source vehicle.
      //! @param[in] data_size size of message data.
      //! @return true if delivery is successful
      bool
      deliverySucceeds(double distance, uint16_t data_size)
      {
        // Out of range
        if (distance > c_max_range)
          return false;

        // Gaussian profiles for distance and msg size
        float dist_prob = exp(-1 * (distance*distance)/(2 * m_args->dst_peak_width * m_args->dst_peak_width));
        float size_prob = exp(-1 * (float)(data_size*data_size)/
                                (2 * m_args->dsize_peak_width * m_args->dsize_peak_width));

        return m_prng->uniform() <= dist_prob*size_prob;
      }

      void
      operationLogic()
      {
        if (m_operation->is_tx) // Transmission Op
        {
          std::string str;
          try
          {
            share(&m_operation->msg);
            str = "DONE";
          }
          catch (std::runtime_error& e)
          {
            str = "FAILED";
            str += e.what();
          }
          dispatch(str);
        }
        else // Reception Op
        {
          m_operation->msg.setDestination(m_task->getSystemId());
          m_operation->msg.setDestinationEntity(m_task->getEntityId());

          m_task->dispatch(&m_operation->msg, DF_LOOP_BACK);

          IMC::SimAcousticMessage request = m_operation->msg;
          if (request.flags == IMC::SimAcousticMessage::SAM_ACK)
            sendRangeReply(&request);
        }
      }
      
      //! Main.
      //! Check for valid curret operation and execute.
      void
      run()
      {
        while (!isStopping())
        {
          checkIncomingData();
          m_operation = m_queue.check(); 

          if (m_operation)
            operationLogic();
        }
      }

      //! Build range request reply and send.
      //! @param[in] range_request range request message.
      void 
      sendRangeReply(const IMC::SimAcousticMessage* range_request)
      {
        IMC::UamTxFrame msg;
        msg.seq = range_request->seq;
        msg.sys_dst = range_request->sys_src;
        msg.flags = IMC::SimAcousticMessage::SAM_REPLY;

        transmit(msg);
      }

      //! Dispatch DevDataText to acoustic modem task.
      //! @param[in] str string to send.
      void
      dispatch(const std::string& str)
      {
        IMC::DevDataText msg;
        msg.setDestination(m_task->getSystemId());
        msg.setDestinationEntity(m_task->getEntityId());
        msg.value.assign(str);
        m_task->dispatch(msg, DF_LOOP_BACK);
      }

      void
      debugMessage(std::string str, const IMC::Message* msg)
      {
        str = str + "\n%s";
        std::stringstream ss;
        msg->toText(ss);
        m_task->debug(DTR(str.c_str()), ss.str().c_str());
      }
    };
  }
}

#endif
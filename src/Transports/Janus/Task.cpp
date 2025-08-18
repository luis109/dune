//***************************************************************************
// Copyright 2007-2025 Universidade do Porto - Faculdade de Engenharia      *
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
// Author: Luis Venâncio (Based on Transports.UAN)                          *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Local headers.
#include "Parser.hpp"

namespace Transports
{
  namespace Janus
  {
    using DUNE_NAMESPACES;

    struct Arguments
    {
      
    };

    struct Task: public DUNE::Tasks::Task
    {
      //! Sequence number. Starts at 0x7FFF, 
      //! so as not to overlap with reqids from Transports.UAN.
      uint16_t m_reqid;
      //! Map of messages to send
      std::map<uint16_t, IMC::UamJanusPacket*> m_transmission_requests;
      //! Timer for sending preceding message
      Counter<double> m_msg_send_timer;
      //! When "false" processQueue must wait
      bool m_can_send;
      //! Time scale convertion for reserve time and repeat interval.
      Parser m_parser;
      //! Task arguments.
      Arguments m_args;

      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        m_reqid(0x7FFF),
        m_can_send(true),
        m_parser(this)
      {
        // Bind messages.
        bind<IMC::UamJanusPacket>(this);
        bind<IMC::UamRxFrame>(this);
        bind<IMC::UamTxStatus>(this);

        m_msg_send_timer.setTop(2);
      }

      void
      onResourceAcquisition(void)
      {
        
      }

      //! Initialize resources.
      void
      onResourceInitialization(void)
      {
        IMC::AnnounceService announce;
        announce.service = std::string("imc+any://janus");
        dispatch(announce);

        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
      }

      //! Release resources.
      void
      onResourceRelease(void)
      {
        
      }

      void
      consume(const IMC::UamJanusPacket* msg)
      {
        if (msg->getSource() != getSystemId()
            || msg->getDestination() != getSystemId())
          return;
          
        if (msg->op != IMC::UamJanusPacket::OP_SEND_REQ)
          return;

        // Send here
        
      }

      void
      consume(const IMC::UamRxFrame* msg)
      {
        // Deserialize the baseline packet.
        if (msg->flags == IMC::UamRxFrame::URF_JANUS_BASELINE)
        {
          IMC::UamJanusPacket baseline;
          m_parser.deserializeBaseline(msg->data, baseline);
          dispatch(baseline);
        }
        else if (msg->flags == IMC::UamRxFrame::URF_JANUS_CARGO)
        {
          // Handle cargo packet.
        }
      }

      void
      consume(const IMC::UamTxStatus* msg)
      {
        if (msg->getDestination() != getSystemId())
          return;

        if (msg->getDestinationEntity() != getEntityId())
          return;

        if (m_transmission_requests.find(msg->seq)
            == m_transmission_requests.end()) {
          return;
        }
        uint16_t idOfMsg = msg->seq;

        const IMC::UamJanusPacket* request = m_transmission_requests[idOfMsg];

        switch (msg->value) {
          case IMC::UamTxStatus::UTS_BUSY:
            // sendAcousticStatus(request,IMC::AcousticStatus::STATUS_BUSY,msg->error);
            m_msg_send_timer.setTop(2);
            m_can_send = true;
            break;

          case IMC::UamTxStatus::UTS_INV_ADDR:
            // sendAcousticStatus(request,IMC::AcousticStatus::STATUS_UNSUPPORTED,msg->error);
            removeFromQueue(idOfMsg);

            break;

          case IMC::UamTxStatus::UTS_DONE:
            // sendAcousticStatus(request,IMC::AcousticStatus::STATUS_SENT,msg->error);
            removeFromQueue(idOfMsg);
            break;

          case IMC::UamTxStatus::UTS_IP:
            // sendAcousticStatus(request,IMC::AcousticStatus::STATUS_IN_PROGRESS,msg->error);

            break;

          case IMC::UamTxStatus::UTS_FAILED:
            // sendAcousticStatus(request,IMC::AcousticStatus::STATUS_ERROR,msg->error);
            removeFromQueue(idOfMsg);

            break;

          default:
            break;

        }
      }

      uint16_t
      createInternalId(){
        if(m_reqid==0xFFFF){
          m_reqid=0;
        }
        else{
          m_reqid++;
        }
        return m_reqid;
      }

      //! Add message to the end of queue
      void
      addToQueue(const IMC::UamJanusPacket* msg)
      {
        m_transmission_requests[createInternalId()] = msg->clone();
      }

      //! Remove message from the queue. Resets timer. And unlocks the queue
      void
      removeFromQueue(uint16_t index)
      {
        delete m_transmission_requests.find(index)->second;
        m_transmission_requests.erase(index);
        m_msg_send_timer.setTop(2);
        m_can_send = true;
      }

      void
      sendFrame(const std::string& sys, const uint16_t id, const std::vector<uint8_t>& data, bool ack)
      {
        Algorithms::CRC8 crc(c_poly);

        IMC::UamTxFrame frame;
        frame.setSource(getSystemId());
        frame.setSourceEntity(getEntityId());
        frame.setDestination(getSystemId());
        frame.sys_dst = sys;
        frame.seq = id;
        frame.flags = ack ? IMC::UamTxFrame::UTF_ACK : 0;

        frame.data.push_back(c_sync);
        crc.putByte(c_sync);
        for (size_t i = 0; i < data.size(); ++i)
        {
          frame.data.push_back(data[i]);
          crc.putByte(data[i]);
        }
        frame.data.push_back(crc.get());

        dispatch(frame);
      }

      void
      sendFrameRaw(const std::string& sys, const uint16_t id, const std::vector<uint8_t>& data, bool ack)
      {
        IMC::UamTxFrame frame;
        frame.setSource(getSystemId());
        frame.setSourceEntity(getEntityId());
        frame.setDestination(getSystemId());
        frame.sys_dst = sys;
        frame.seq = id;
        frame.flags = ack ? IMC::UamTxFrame::UTF_ACK : 0;

        for (size_t i = 0; i < data.size(); ++i)
        {
          frame.data.push_back(data[i]);
        }

        dispatch(frame);
      }

      void
      sendMessage(const std::string& sys, const uint16_t id, const InlineMessage<IMC::Message>& imsg)
      {
        const IMC::Message* msg = NULL;

        try
        {
          msg = imsg.get();
        }
        catch (...)
        {
          return;
        }

        // Check if special command can be used...
        if (msg->getId() == IMC::PlanControl::getIdStatic())
        {
          const IMC::PlanControl * pc = static_cast<const IMC::PlanControl*>(msg);
          if (pc->arg.isNull())
          {
            sendPlanControl(sys, id, static_cast<const IMC::PlanControl*>(msg));
            return;
          }
        }

        // For all other cases, send the raw message across
        sendRawMessage(sys, id, msg);
      }

      void
      sendRawMessage(const std::string& sys, const uint16_t id, const IMC::Message * msg)
      {
        std::vector<uint8_t> data;
        data.push_back(CODE_RAW);

        inf("Send message of type %s, with serialization size %d.", msg->getName(), msg->getSerializationSize());

        // leave 1 byte for CODE_RAW and another for CRC8
        uint8_t buf[2500];

        // start with message id
        uint16_t id2 = msg->getId();
        std::memcpy(&buf[0], &id2, sizeof(uint16_t));

        // followed by all message fields
        msg->serializeFields(&buf[2]);

        int length = msg->getSerializationSize() + 2;
        data.insert(data.end(), buf, buf + length);
        sendFrame(sys, id, data, true);
      }

      void
      sendRaw(const IMC::AcousticRequest& req, const std::string& sys, const uint16_t id, const InlineMessage<IMC::Message>& imsg)
      {
        const IMC::Message* msg = NULL;

        try
        {
          msg = imsg.get();
        }
        catch (...)
        {
          sendAcousticStatus(&req, IMC::AcousticStatus::STATUS_INPUT_FAILURE, "Null pointer.");
          removeFromQueue(req.req_id);
          return;
        }

        // Check if is DevDataBinary...
        if (msg->getId() == IMC::DevDataBinary::getIdStatic())
        {
          const IMC::DevDataBinary * ddb = static_cast<const IMC::DevDataBinary*>(msg);
          if (ddb->value.size() > 0)
          {
            std::vector<uint8_t> data;
            // no coding, send as is
            for (size_t i = 0; i < ddb->value.size(); ++i)
            {
              data.push_back(ddb->value[i]);
            }

            sendFrameRaw(sys, id, data, true);
            return;
          }
        }

        sendAcousticStatus(&req, IMC::AcousticStatus::STATUS_UNSUPPORTED, "Unsupported type for raw send.");
        removeFromQueue(req.req_id);
      }

      void
      recvMessage(uint16_t imc_src, uint16_t imc_dst, const IMC::UamRxFrame* msg)
      {
        // debug("Parsing message received via acoustic message.");

        // try
        // {
        //   uint16_t msg_type;
        //   std::memcpy(&msg_type, &msg->data[2], sizeof(uint16_t));
        //   Message *m = IMC::Factory::produce(msg_type);
        //   if (m == NULL)
        //   {
        //     err("Invalid message type received: %d", msg_type);
        //     return;
        //   }

        //   m->setSource(imc_src);
        //   m->setDestination(imc_dst);
        //   m->setTimeStamp(msg->getTimeStamp());
        //   m->deserializeFields((const unsigned char *)&msg->data[4], msg->data.size()-4);

        //   // mark the message's origin as acoustic if it is an acoustic command
        //   if (m->getId() == IMC::TextMessage::getIdStatic())
        //   {
        // 	IMC::TextMessage* txtmsg = static_cast<IMC::TextMessage*>(m);
        // 	std::stringstream ss;
        // 	ss << "acoustic/" << msg->sys_src;
        // 	txtmsg->origin = ss.str();
        //   }

        //   dispatch(m, DF_KEEP_TIME | DF_LOOP_BACK);
        //   debug("Acoustic message successfully parsed as '%s'.", m->getName());
        // }
        // catch (std::exception& ex) {
        //   err("Error parsing raw message from UAM frame: %s.", ex.what());
        // }
      }

      void
      clearTimeouts()
      {
        // Maybe we add timeout to IMC::UamJanusPacket


        // std::map<uint16_t, IMC::AcousticRequest*>::iterator it;
        // it = m_transmission_requests.begin();

        // while (it != m_transmission_requests.end())
        // {
        //   if (it->second->getTimeStamp() + it->second->timeout <= Clock::getSinceEpoch())
        //   {
        //     sendAcousticStatus(it->second,IMC::AcousticStatus::STATUS_INPUT_FAILURE,"Transmission timed out.");
        //     Memory::clear(it->second);
        //     m_transmission_requests.erase(it++);
        //     m_can_send = true;
        //   }
        //   else
        //     ++it;
        // }
      }

      void
      processQueue(void)
      {
        if (m_can_send && !m_transmission_requests.empty())
        {
          m_can_send = false;
          const IMC::UamJanusPacket* req = m_transmission_requests.begin()->second;
          uint16_t id = m_transmission_requests.begin()->first;

          // Serialize Janus packet and send it.
        }
      }

      //! Main loop.
      void
      onMain(void)
      {
        while (!stopping())
        {
          waitForMessages(1.0);

          if(m_msg_send_timer.overflow())
          {
            clearTimeouts();
            processQueue();
          }
        }
      }
    };
  }
}

DUNE_TASK

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
// written agreement between you and Universidade do Porto. For licensing   *
// terms, conditions, and further information contact lsts@fe.up.pt.        *
//                                                                          *
// European Union Public Licence - EUPL v.1.1 Usage                         *
// Alternatively, this file may be used under the terms of the EUPL,        *
// Version 1.1 only (the "Licence"), appearing in the file LICENCE.md       *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// http://ec.europa.eu/idabc/eupl.html.                                     *
//***************************************************************************
// Author: Luís Venâncio                                                    *
//***************************************************************************

#ifndef MANEUVER_SWARM_ACOUSTICPROTOCOL_HPP_INCLUDED_
#define MANEUVER_SWARM_ACOUSTICPROTOCOL_HPP_INCLUDED_

#include <DUNE/Tasks.hpp>
#include <DUNE/Utils/String.hpp>

namespace DUNE
{
  namespace Swarm
  {
    // Synchronization byte.
    static const uint8_t c_sync = 0xA2;
    static const uint8_t c_poly = 0x07;

    enum Codes
    {
      CODE_SETUP  = 0x00,
      CODE_NEXT   = 0x01
    };

    struct Point
    {
      float lat;
      float lon;
    };

    struct Setup
    {
      uint8_t formation_id;
      float offset_x;
      float offset_y;
      float offset_z;
    };

    //! Takeoff maneuver
    class AcousticProtocol
    {
    public:
      //! Default constructor.
      AcousticProtocol(Tasks::Task* task):
        m_task(task)
      { }

      void
      sendNext(const std::string& sys, float lat, float lon)
      {
        std::vector<uint8_t> data;

        Point p;
        p.lat = lat;
        p.lon = lon;

        data.resize(sizeof(p) + 1);
        data[0] = CODE_NEXT;
        std::memcpy(&data[1], &p, sizeof(p));

        sendFrame(sys, 0, data, false);
      }

      void
      sendFrame(const std::string& sys, const uint16_t id, const std::vector<uint8_t>& data, bool ack)
      {
        Algorithms::CRC8 crc(c_poly);

        IMC::UamTxFrame frame;
        frame.setSource(m_task->getSystemId());
        frame.setSourceEntity(m_task->getEntityId());
        frame.setDestination(m_task->getSystemId());
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

        m_task->dispatch(frame);
      }

      bool
      validate(const IMC::UamRxFrame* msg)
      {
        if (msg->data.size() < 2)
        {
          debug("invalid message size");
          return false;
        }

        uint16_t imc_addr_src = 0;
        try
        {
          imc_addr_src = m_task->resolveSystemName(msg->sys_src);
          war(DUNE::Utils::String::str("Received msg from: %s", msg->sys_src.c_str()));
        }
        catch (...)
        {
          debug(DUNE::Utils::String::str("unknown system name: %s", msg->sys_src.c_str()));
          return false;
        }

        (void)imc_addr_src;

        uint16_t imc_addr_dst = 0;
        try
        {
          imc_addr_dst = m_task->resolveSystemName(msg->sys_dst);
          war(DUNE::Utils::String::str("Received msg destination: %s", msg->sys_dst.c_str()));
        }
        catch (...)
        {
          debug(DUNE::Utils::String::str("unknown system name: %s", msg->sys_dst.c_str()));
          return false;
        }

        (void)imc_addr_dst;

        if ((uint8_t)msg->data[0] != c_sync)
        {
          debug(DUNE::Utils::String::str("invalid synchronization number: %02X", msg->data[0]));
          return false;
        }

        Algorithms::CRC8 crc(c_poly);
        crc.putArray((uint8_t*)&msg->data[0], msg->data.size() - 1);
        if (crc.get() != (uint8_t)(msg->data[msg->data.size() - 1]))
        {
          debug("invalid CRC");
          return false;
        }

        return true;
      }

    private:
      Tasks::Task* m_task;

      void
      debug(const std::string& msg) const
      {
        m_task->debug("[AcousticProtocol] >> %s", msg.c_str());
      }

      void
      war(const std::string& msg) const
      {
        m_task->war("[AcousticProtocol] >> %s", msg.c_str());
      }
    };
  }
}

#endif

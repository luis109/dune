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
// Author: Luis Venancio                                                    *
//***************************************************************************

// Local headers
#include "CommandProtocol.hpp"

namespace Power
{
  namespace GHPB
  {
    CommandProtocol::CommandProtocol(Tasks::Task* task, IO::Handle* handle):
    m_task(task),
    m_handle(handle)
    {
      m_buffer.resize(c_nmea_max_length);
    }

    bool
    CommandProtocol::decode(Command& cmd, NMEASentence& sentence)
    {
      //Clear command
      cmd.reset();
      char bfr[16];

      printf("decode start\n");
      // Command must have at least a type
      if (!sentence.getField(0, &cmd.m_type))
        return false;
      printf("decode got type\n");
      if (!sentence.getField(1, &cmd.m_dev))
        return true;

      if (!sentence.getField(2, bfr))
        return true;
      cmd.m_dev_num = atoi(bfr);

      if (!sentence.getField(3, bfr))
        return true;
      cmd.m_val[0] = atoi(bfr);

      if (!sentence.getField(4, bfr))
        return true;
      cmd.m_val[1] = atoi(bfr);

      return true;
    }

    void
    CommandProtocol::encode(Command& cmd, NMEASentence& sentence)
    {
      sentence.addField(cmd.m_type);
      sentence.addField(cmd.m_dev);

      if (cmd.m_dev_num != (uint16_t)(-1)) // Invalid (uint16_t)(-1)
        sentence.addField(cmd.m_dev_num);

      for (uint8_t i = 0; i < 2; i++)
      {
        if (cmd.m_val[i] != (uint16_t)(-1)) // Invalid (uint16_t)(-1)
          sentence.addField(cmd.m_val[i]);
      }
    }

    bool 
    CommandProtocol::receiveCommand(Command& cmd)
    {
      if (!Poll::poll(*m_handle, 1.0))
        return false;
      
      size_t rv = m_handle->read(&m_buffer[0], m_buffer.size());
      if (rv == 0)
        throw std::runtime_error(DTR("invalid read size"));

      m_task->trace("RxMsg: %s", &m_buffer[0]);
      NMEASentence sentence(&m_buffer[0]);
      if (!decode(cmd, sentence))
        return false;

      m_task->spew("RxCmd type: %c", cmd.m_type);
      m_task->spew("RxCmd device: %c", cmd.m_dev);
      m_task->spew("RxCmd device num: %u", cmd.m_dev_num);
      m_task->spew("RxCmd val 0: %c", cmd.m_val[0]);
      m_task->spew("RxCmd val 1: %c", cmd.m_val[1]);

      return true;
    }

    bool 
    CommandProtocol::sendCommand(Command& cmd)
    {
      m_task->spew("TxCmd type: %c", cmd.m_type);
      m_task->spew("TxCmd device: %c", cmd.m_dev);
      m_task->spew("TxCmd device num: %u", cmd.m_dev_num);
      m_task->spew("TxCmd val 0: %c", cmd.m_val[0]);
      m_task->spew("TxCmd val 1: %c", cmd.m_val[1]);

      NMEASentence sentence;
      encode(cmd, sentence);

      sentence.getSentence(&m_buffer[0]);
      m_task->trace("TxMsg: %s", &m_buffer[0]);

      return m_handle->writeString(&m_buffer[0]) > 0;
    }

    bool
    CommandProtocol::sendOk()
    {
      NMEASentence sentence;

      sentence.addField("OK");
      sentence.getSentence(&m_buffer[0]);

      return m_handle->writeString(&m_buffer[0]) > 0;
    }

    bool
    CommandProtocol::sendError(const char* error_msg)
    {
      NMEASentence sentence;
      
      sprintf(&m_buffer[0], "ERROR,%s", error_msg);
      sentence.addField(&m_buffer[0]);
      sentence.getSentence(&m_buffer[0]);

      return m_handle->writeString(&m_buffer[0]) > 0;
    }
  }
}
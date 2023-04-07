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

#ifndef POWER_GHPB_COMMAND_PROTOCOL_HPP_INCLUDED_
#define POWER_GHPB_COMMAND_PROTOCOL_HPP_INCLUDED_

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Local headers
#include "NMEASentence.hpp"

namespace Power
{
  namespace GHPB
  {
#define CP_BUFFER_SIZE 128

    enum
    {
      CMD_DEV_MOTOR = 'M',
      CMD_DEV_PWM = 'P',
      CMD_DEV_RELAY = 'R',
      CMD_DEV_WAKEUP = 'W',
      CMD_DEV_VERSION = 'V'
    };

    enum
    {
      CMD_TYPE_SET = 'S',
      CMD_TYPE_GET = 'G',
      CMD_TYPE_INFO = 'I'
    };
    struct Command
    {
      char m_type;
      char m_dev;
      uint16_t m_dev_num;
      uint16_t m_val[2];

      Command()
      {
        reset();
      }

      void
      reset()
      {
        m_type = '\0';
        m_dev = '\0';
        m_dev_num = -1;
        m_val[0] = -1;
        m_val[1] = -1;
      }
    };

    class CommandProtocol
    {
      public:
        CommandProtocol(Tasks::Task* task, IO::Handle* handle);
        
        bool 
        receiveCommand(Command& cmd);

        bool 
        sendCommand(Command& cmd);

        bool 
        sendError(const char* error_msg);

        bool 
        sendOk();

      private:
        //! Task handler
        Tasks::Task* m_task;
        //! Serial port handle.
        IO::Handle* m_handle;
        //! Receive buffer
        std::vector<char> m_buffer;

        bool 
        decode(Command& cmd, NMEASentence& sentence);

        void 
        encode(Command& cmd, NMEASentence& sentence);
    };
  }
}



#endif
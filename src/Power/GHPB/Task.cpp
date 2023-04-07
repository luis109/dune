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

// ISO C++ 98 headers.
#include <algorithm>
#include <cstddef>
#include <cstring>

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Local headers.
#include "PowerChannels.hpp"
#include "CommandProtocol.hpp"

namespace Power
{
  //! Device driver for NMEA capable %GPS devices.
  namespace GHPB
  {
    using DUNE_NAMESPACES;

    struct Arguments
    {
      //! IO device (URI).
      std::string io_dev;
    };

    struct Task: public Hardware::BasicDeviceDriver
    {
      //! Serial port handle.
      IO::Handle* m_handle;
      //! Task arguments.
      Arguments m_args;
      //! Command protocol handler
      CommandProtocol* m_cmd_protocol;

      Task(const std::string& name, Tasks::Context& ctx):
        Hardware::BasicDeviceDriver(name, ctx),
        m_handle(NULL)
      {
        // Define configuration parameters.
        paramActive(Tasks::Parameter::SCOPE_GLOBAL,
                    Tasks::Parameter::VISIBILITY_DEVELOPER, 
                    true);
                    
        param("IO Port - Device", m_args.io_dev)
        .defaultValue("")
        .description("IO device URI in the form \"uart://DEVICE:BAUD\"");

        // Use wait for messages
        setWaitForMessages(1.0);
      }

      void
      onUpdateParameters(void)
      {
      }

      //! Try to connect to the device.
      //! @return true if connection was established, false otherwise.
      bool
      onConnect() override
      {
        try
        {
          m_handle = openDeviceHandle(m_args.io_dev);
          m_cmd_protocol = new CommandProtocol(this, m_handle);
          return true;
        }
        catch (...)
        {
          throw RestartNeeded(DTR(Status::getString(CODE_COM_ERROR)), 5);
        }

        return false;
      }

      //! Disconnect from device.
      void
      onDisconnect() override
      {
        Memory::clear(m_handle);
        Memory::clear(m_cmd_protocol);
      }

      //! Initialize device.
      void
      onInitializeDevice() override
      {
        getVersion();
      }

      bool
      waitForReply(Command& cmd, const double timeout = 1.5)
      {
        Counter<double> tout;
        tout.setTop(timeout);
        
        while (!tout.overflow())
        {
          if (!!m_cmd_protocol->receiveCommand(cmd))
            continue;
          else
            return true;
        }

        return false;
      }

      bool
      getVersion()
      {
        Command version_cmd;
        Command version_rpl;

        version_cmd.m_type = CMD_TYPE_GET;
        version_cmd.m_dev = CMD_DEV_VERSION;
        version_cmd.m_dev_num = 0;
        m_cmd_protocol->sendCommand(version_cmd);
        
        if (waitForReply(version_rpl))
        {
          if (version_rpl.m_type == CMD_TYPE_INFO && 
              version_rpl.m_dev == CMD_DEV_VERSION &&
              version_rpl.m_val[0] == 1)
            return true;
        }

        return false;
      }

      //! Check for input timeout.
      //! Data is read in the DevDataText consume.
      //! @return true.
      bool
      onReadData() override
      {

        return true;
      }
    };
  }
}

DUNE_TASK

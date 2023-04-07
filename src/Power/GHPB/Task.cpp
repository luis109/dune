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

    //! Number of Power channels.
    static const unsigned c_pwrs_count = 5;

    struct Arguments
    {
      //! IO device (URI).
      std::string io_dev;
      //! IO device (URI).
      uint16_t firmware_version;
      //! Power channels names.
      std::string pwr_names[c_pwrs_count];
      //! Power channels states.
      unsigned pwr_states[c_pwrs_count];
    };

    struct Task: public Hardware::BasicDeviceDriver
    {
      //! Serial port handle.
      IO::Handle* m_handle;
      //! Task arguments.
      Arguments m_args;
      //! Command protocol handler
      CommandProtocol* m_cmd_protocol;
      //! Power channels.
      PowerChannels m_pwr_channels;

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
                    
        param("Firmware Version", m_args.firmware_version)
        .defaultValue("1")
        .description("Firmware version sent by GHPB");

        for (unsigned i = 0; i < c_pwrs_count; ++i)
        {
          std::string option = String::str("Power Channel %u - Name", i);
          param(option, m_args.pwr_names[i]);

          option = String::str("Power Channel %u - State", i);
          param(option, m_args.pwr_states[i])
          .defaultValue("0");
        }

        // Use wait for messages
        setWaitForMessages(1.0);
      }

      void
      onUpdateParameters(void)
      {
        m_pwr_channels.clear();
        for (unsigned i = 0; i < c_pwrs_count; ++i)
        {
          PowerChannel* channel = new PowerChannel;
          channel->id = i;
          channel->state.name = m_args.pwr_names[i];
          if (m_args.pwr_states[i] == 1)
            channel->state.state = IMC::PowerChannelState::PCS_ON;
          else
            channel->state.state = IMC::PowerChannelState::PCS_OFF;
          m_pwr_channels.add(i, channel);
        }
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
        wait(1.0);

        if (!getVersion())
          throw RestartNeeded("Unable to get correct version", 5.0);
        
        if (!commandWakeup(true))
          throw RestartNeeded("Unable to wakeup device", 5.0);
        
        for (auto pc : m_pwr_channels)
          commandPowerChannel(pc.second->id, pc.second->state.state);
      }

      bool
      waitForReply(Command& cmd, const double timeout = 1.5)
      {
        Counter<double> timer;
        timer.setTop(timeout);
        
        while (!timer.overflow())
        {
          if (m_cmd_protocol->receiveCommand(cmd))
            return true;
          else
            continue;
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
        
        if (waitForReply(version_rpl, 2.0))
        {
          if (version_rpl.m_type == CMD_TYPE_INFO && 
              version_rpl.m_dev == CMD_DEV_VERSION &&
              version_rpl.m_val[0] == m_args.firmware_version)
            return true;
        }

        return false;
      }

      bool
      commandWakeup(bool state)
      {
        Command cmd;
        Command rpl;

        cmd.m_type = CMD_TYPE_SET;
        cmd.m_dev = CMD_DEV_WAKEUP;
        cmd.m_dev_num = 0;
        cmd.m_val[0] = state;
        m_cmd_protocol->sendCommand(cmd);
        
        if (waitForReply(rpl))
        {
          if (rpl.m_type == CMD_TYPE_INFO && rpl.m_dev == CMD_DEV_ACK)
            return true;
        }

        return false;
      }

      bool
      commandPowerChannel(unsigned id, bool state)
      {
        Command cmd;
        Command rpl;

        cmd.m_type = CMD_TYPE_SET;
        cmd.m_dev = CMD_DEV_RELAY;
        cmd.m_dev_num = id;
        cmd.m_val[0] = state;
        m_cmd_protocol->sendCommand(cmd);
        
        if (waitForReply(rpl))
        {
          if (rpl.m_type == CMD_TYPE_INFO && rpl.m_dev == CMD_DEV_ACK)
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

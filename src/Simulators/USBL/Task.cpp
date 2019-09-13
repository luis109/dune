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
// Authors: Pedro Calado / Renan Maidana / Luis Venancio                    *
//***************************************************************************

// TODO: Make sure we can communicate with the Seatrac driver through the IOHandle


// ISO C++ 98 headers.
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Local headers
#include "Parser.hpp"

// // PTY
// #include <errno.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <string.h>
// #include <sys/stat.h>
// #include <termios.h>
#include <unistd.h>

using namespace std;

namespace Simulators
{
  namespace USBL
  {
    using DUNE_NAMESPACES;

    struct Arguments
    {
      //! Beacon ID
      uint8_t beacon_ID;
      //! Serial port device.
      std::string uart_dev;
      //! Serial port baud rate.
      unsigned uart_baud;
      //! USBL latitude coordinate
      double usbl_lat;
      //! USBL longitude coordinate
      double usbl_lon;
      //! Heading angle of the USBL mount
      double usbl_heading;
      //! Depth of the USBL transducer
      double usbl_depth;
      //! USBL Slant range accuracy
      double usbl_slant_acc;
      //! USBL Bearing Resolution
      double usbl_bearing_res;
      //! EEPROM file name
      std::string sim_eeprom_file;
    };

    struct Task: public DUNE::Tasks::Task
    {
      //! TCP socket handles
      TCPSocket* m_sock;
      TCPSocket* m_nc;

      //! TCP socket port (parsed from uart_dev)
      unsigned m_sock_port;

      // I/O Multiplexer.
      Poll m_poll;

      //! Beacon data structure
      DataSeatrac m_data_beacon;
      //! Current position.
      IMC::SimulatedState m_sstate;
      //! North offset of the USBL acoustic transducer
      double m_usbl_off_n;
      //! East offset of the USBL acoustic transducer
      double m_usbl_off_e;
      //! Task Arguments.
      Arguments m_args;

      //! Strings for data keeping
      std::string m_data;
      std::string m_datahex;

      //! c_preamble detected
      bool m_pre_detected;

      //! Current entity state.
      IMC::EntityState m_state_entity;

      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        m_sock(NULL)
      {
        param("Beacon ID", m_args.beacon_ID)
        .defaultValue("1")
        .description("Beacon identification number (1 to 15)");

        param("Serial Port - Device", m_args.uart_dev)
        .defaultValue("/tmp/seatrac")        
        .description("Serial port to which the simulated device will be attached to");

        param("Serial Port - Baud Rate", m_args.uart_baud)
        .defaultValue("19200")
        .description("Serial port baud rate");
        
        param("Latitude", m_args.usbl_lat)
        .defaultValue("0.0")
        .units(Units::Degree)
        .description("Latitude coordinate of the USBL transducer location");

        param("Longitude", m_args.usbl_lon)
        .defaultValue("0.0")
        .units(Units::Degree)
        .description("Longitude coordinate of the USBL transducer location");

        param("Mounted Heading", m_args.usbl_heading)
        .defaultValue("0.0")
        .units(Units::Degree)
        .description("Heading angle at which the transducer was mounted");

        param("Mounted Depth", m_args.usbl_depth)
        .defaultValue("2.0")
        .units(Units::Meter)
        .description("Depth at which the transducer was mounted");

        param("Slant Range Accuracy", m_args.usbl_slant_acc)
        .defaultValue("0.01")
        .units(Units::Meter)
        .description("Sensor's slant range accuracy");

        param("Bearing Resolution", m_args.usbl_bearing_res)
        .defaultValue("0.1")
        .units(Units::Degree)
        .description("Sensor's bearing resolution");
      
        param("Simulated EEPROM File", m_args.sim_eeprom_file)
         .defaultValue("SIM_EEPROM_MEM")
         .description("File name of simulated EEPROM file");

        bind<IMC::GpsFix>(this);
        bind<IMC::SimAcousticMessage>(this);
      }
      
      //! Task destructor
      ~Task(void)
      {
        onResourceRelease();
      }
      
      void
      onResourceAcquisition(void)
      {
        setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_CONNECTING);
        inf("Acquiring socket resource");
        try
        {
          m_sock = new TCPSocket;
          m_nc = new TCPSocket;
        }
        catch (std::runtime_error& e)
        {
          throw RestartNeeded(e.what(), 30);
        }
      }

      void
      onResourceInitialization(void)
      {
        inf("Initializing socket resource");
        try
        {
          char socket_addr[128] = { 0 };

          // Get socket address and port from config file string
          std::sscanf(m_args.uart_dev.c_str(), "tcp://%[^:]:%u", socket_addr, &m_sock_port);
          
          // Bind and listen to socket
          m_sock->bind(m_sock_port);
          m_sock->listen(1024);
          m_sock->setNoDelay(true);
          m_poll.add(*m_sock);
        }
        catch (std::runtime_error& e)
        {
          throw RestartNeeded(e.what(), 30);
        }

        inf("Reading beacon settings from simulated EEPROM");
        getSettingsEEPROM(m_args.sim_eeprom_file.c_str(), m_data_beacon);

        setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_WAIT_GPS_FIX);
      }

      void
      onResourceRelease(void)
      {
        if (m_sock != NULL)
        {
          m_poll.remove(*m_sock);
          delete m_sock;
          m_sock = NULL;
        }

        if(m_nc != NULL){
          m_poll.remove(*m_nc);
          delete m_nc;
          m_nc = NULL;
        }
      }

      void
      onUpdateParameters(void)
      {
        if (paramChanged(m_args.usbl_lat))
          m_args.usbl_lat = Angles::radians(m_args.usbl_lat);

        if (paramChanged(m_args.usbl_lon))
          m_args.usbl_lon = Angles::radians(m_args.usbl_lon);

        if (paramChanged(m_args.usbl_heading))
          m_args.usbl_heading = Angles::normalizeRadian(Angles::radians(m_args.usbl_heading));

        if (paramChanged(m_args.usbl_bearing_res))
          m_args.usbl_bearing_res = Angles::radians(m_args.usbl_bearing_res);
      }

      // Received a new acoustic message
      void consume(const IMC::SimAcousticMessage* msg){
        // If sender is myself, ignore the message
        if (msg->getSource() != getSystemId())
          return;

        std::string recvSentence = String::fromHex(msg->sentence);
        inf("Received sentence: %s", recvSentence.c_str());
      }

      //! Process sentence.
      //! @return true if message was correctly processed, false otherwise.
      bool
      processSentence(void)
      {
        bool msg_validity = false;
        uint16_t crc, crc2;
        if(m_data.size() >= MIN_MESSAGE_LENGTH)
        {
          std::string msg = String::fromHex(m_data.substr((m_data.size() - 4), 4));
          std::memcpy(&crc2, msg.data(), 2);
          m_datahex = String::fromHex(m_data.erase((m_data.size() - 4), 4));
          crc = CRC16::compute((uint8_t*) m_datahex.data(), m_datahex.size(),0);
          if (crc == crc2)
            msg_validity = true;
          else
            war("%s", DTR(Status::getString(Status::CODE_INVALID_CHECKSUM)));
        }
        return msg_validity;
      }

      //! Read sentence.
      void
      readSentence(void)
      {
        // Initialize received message parser
        char bfr[Transports::Seatrac::c_bfr_size];
        uint16_t typemes = 0;
        const char* msg_raw;
        
        // If there was a new event in the connection socket
        if(m_poll.wasTriggered(*m_nc)){
          // Catch connection and runtime errors
          try
          {
            size_t rv = m_nc->readString(bfr, Transports::Seatrac::c_bfr_size);
            for (size_t i = 0; i < rv; ++i)
            {
              // Detected line termination.
              if (bfr[i] == '\n')
              {
                // If line read has a valid preamble
                if(m_pre_detected==true)
                {
                  // CRC verification
                  if (processSentence())
                  {
                    msg_raw = m_datahex.data();
                    std::memcpy(&typemes, msg_raw, 1);
                    dataParser(typemes, msg_raw + 1, m_data_beacon);
                    typemes = 0;
                    inf("Received: %s", m_data.c_str());
                  }
                }
                m_pre_detected = false;
                m_data.clear();
              }
              else
              {
                // TODO:
                // For now we consider only incoming commands
                // However, we must find out how modems communicate with each other
                // Do they send commands in the same way? 
                // Do they receive responses the same way?
                if (bfr[i] == c_cmd_preamble)
                {
                  m_data.clear();
                  m_pre_detected = true;
                }
                else if (bfr[i] != '\r')
                {
                  m_data.push_back(bfr[i]);
                }
              }
            }
          }
          catch (Network::ConnectionClosed& e)
          {
            // If connection was closed, delete client-side connection and exit procedure
            war("Connection closed by client");
            (void)e;
            m_poll.remove(*m_nc);
            delete m_nc;
            m_nc = NULL;
            return;
          }
          catch (std::runtime_error& e)
          {
            err("%s", e.what());
          }

          
        }
      }

      void
      consume(const IMC::GpsFix* msg)
      {
        if (msg->type != IMC::GpsFix::GFT_MANUAL_INPUT)
          return;

        WGS84::displacement(msg->lat, msg->lon, 0,
                            m_args.usbl_lat, m_args.usbl_lon, 0,
                            &m_usbl_off_n, &m_usbl_off_e);

        // Here we see the displacement between the modem's gps position and the USBL sensor
        trace("Offsets to navigational reference - North: %0.2f | East: %0.2f", m_usbl_off_n, m_usbl_off_e);

        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
      }
      
      // From Transports.SerialOverTCP
      void
      checkMainSocket(void)
      {
        // Accept new connection if main socket has new event
        if (m_poll.wasTriggered(*m_sock))
        {
          inf(DTR("Accepting connection request"));
          try
          {
            m_nc = m_sock->accept();
            m_poll.add(*m_nc);
          }
          catch (std::runtime_error& e)
          {
            err("%s", e.what());
          }
        }
      }

      void 
      onMain(void){
        inf("Waiting for GPS fix");
        while (getEntityState() != IMC::EntityState::ESTA_NORMAL){
          consumeMessages();
        }
        inf("Got GPS fix");

        inf("Listening to port %d", m_sock_port);
        while(!stopping()){
          if(m_poll.poll(5.0)){   // Wait for receiving in socket with 5 seconds timeout
            checkMainSocket();
            readSentence();
          }
          waitForMessages(0.1);
        } 
      }
    };
  }
}

DUNE_TASK
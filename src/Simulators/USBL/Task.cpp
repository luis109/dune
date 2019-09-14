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
      //! PRNG type
      std::string prng_type;
      //! PRNG seed
      int prng_seed;
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
      bool m_pre_cmd_detected;
      bool m_pre_resp_detected;
      //! Status output rate
      double m_status_rate;
      //! PRNG handle.
      Random::Generator* m_prng;

      //! Current entity state.
      IMC::EntityState m_state_entity;

      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        m_sock(NULL),
        m_prng(NULL)
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
      
      //! Updates the beacon's status data, as if reading the sensors
      // Is there a way to do this via threading? Is there a dune resource for threads?
      // With a thread, the data could be updated without having to wait for the status rate,
      // emulating the modem behavior a bit more realistically
      void
      updateStatus(void)
      {
        // Compute output flags
        std::memcpy(&m_data_beacon.cid_status_msg.output_flags, &m_data_beacon.cid_settings_msg.status_output, 1);
        m_data_beacon.cid_status_msg.outputFlagsComp();

        // Simulate and calculate environmental parameters
        // For now these values are fixed +- some variance to simulate sensor noise
        // Supply voltage
        double voltage = 15.0;  // 15 Volts
        voltage += m_prng->gaussian(0, 0.01);
        // Temperature
        double temperature = 25.0;  // 25 Celsius
        temperature += m_prng->gaussian(0, 0.1);
        // Depth, user-defined
        double depth = __builtin_bswap16(m_data_beacon.cid_status_msg.EnvironmentDepth) / 10.0; // + m_prng->gaussian(m_args.usbl_depth, 0.01);
        // Pressure (user defines mounted depth and we calculate pressure from that)
        double pressure = 0.101*depth + 1.01;  
        // Water salinity (from beacon settings) - Parsed as little endian???
        double salinity = __builtin_bswap16(m_data_beacon.cid_settings_msg.env_salinity) / 10.0;   // PPT
        // Velocity-of-sound in sea-water (according to Mackenzie model, last element is basically zero)
        // Depends on water depth, salinity and temperature
        double vos = 1448.96 + 4.591*temperature - 0.05304*pow(temperature, 2) 
                    + 0.002374*pow(temperature,3) + 1.340*(salinity-35) 
                    + 0.0163010*depth + 0.0000001675*pow(depth,2) 
                    - 0.01025*temperature*(salinity - 35);

        // Get clock timestamp 
        m_data_beacon.cid_status_msg.timestamp = DUNE::Time::Clock::getMsec();

        // Environment.
        // Milli-volts
        m_data_beacon.cid_status_msg.environment_supply = (uint16_t)(voltage*1000);
        // Deci-celsius
        m_data_beacon.cid_status_msg.environment_temperature = (int16_t)(temperature*10);
        // Milli-Bar
        m_data_beacon.cid_status_msg.environment_pressure = (int32_t)(pressure*1000); 
        // Deci-meters-per-second
        m_data_beacon.cid_status_msg.EnvironmentVos = (uint16_t)(vos*10);

        // Attitude - we calculate attitude based on range and displacement?
        m_data_beacon.cid_status_msg.attitude_yaw += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.attitude_pitch += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.attitude_roll += m_prng->gaussian(0, 0.1);

        // AHRS raw data.
        m_data_beacon.cid_status_msg.ahrs_raw_acc_x += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_acc_y += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_acc_z += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_mag_x += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_mag_y += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_mag_z += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_gyro_x += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_gyro_y += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_raw_gyro_z += m_prng->gaussian(0, 0.1);
        
        // AHRS compensated data - How do we compensate it?
        m_data_beacon.cid_status_msg.ahrs_comp_acc_x += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_acc_y += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_acc_z += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_mag_x += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_mag_y += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_mag_z += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_gyro_x += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_gyro_y += m_prng->gaussian(0, 0.1);
        m_data_beacon.cid_status_msg.ahrs_comp_gyro_z += m_prng->gaussian(0, 0.1);
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
            TCPSocket* nc = m_sock->accept();
            m_clients.push_back(nc);
            m_poll.add(*nc);
          }
          catch (std::runtime_error& e)
          {
            err("%s", e.what());
          }
        }
      }

      void
      checkClientSockets(void)
      {
              
        std::list<TCPSocket*>::iterator itr = m_clients.begin();
        while (itr != m_clients.end())
        {
          if (m_poll.wasTriggered(*(*itr)))
          {
            char bfr[Transports::Seatrac::c_bfr_size];
            try
            {
              size_t rv = (*itr)->readString(bfr, Transports::Seatrac::c_bfr_size);
              readSentence(bfr, rv);
            }
            catch (Network::ConnectionClosed& e)
            {
              (void)e;
              m_poll.remove(*(*itr));
              delete *itr;
              itr = m_clients.erase(itr);
              continue;
            }
            catch (std::runtime_error& e)
            {
              err("%s", e.what());
            }
          }
          ++itr;
        }
      }

      // Send data back to clients (from Transports.SerialOverTCP)
      void
      dispatchToClients(const char* bfr, size_t bfr_len)
      {
        std::list<TCPSocket*>::iterator itr = m_clients.begin();
        while (itr != m_clients.end())
        {
          try
          {
            (*itr)->write(bfr, bfr_len);
            ++itr;
          }
          catch (std::runtime_error& e)
          {
            err("%s", e.what());
            m_poll.remove(*(*itr));
            delete *itr;
            itr = m_clients.erase(itr);
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

          if(m_poll.poll(0.01)){
            checkMainSocket();    // Expect connection
            checkClientSockets(); // Receive data
          }

          // Get new "sensor" measurements
          updateStatus();

          // If there is a client, send current modem status to it
          string status = responseCreateSeatrac(Transports::Seatrac::CID_STATUS, m_data_beacon);
          dispatchToClients(status.c_str(), status.length());

          // Get messages and wait status update rate
          waitForMessages(0.01);
          Delay::wait(m_status_rate);
        }

        onResourceRelease(); 
      }
    };
  }
}

DUNE_TASK
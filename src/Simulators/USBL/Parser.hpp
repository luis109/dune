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
// Author: João Teixeira                                                    *
// Author: Raúl Sáez                                                        *
//***************************************************************************

#ifndef SIMULATORS_USBL_PARSER_HPP_INCLUDED_
#define SIMULATORS_USBL_PARSER_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Local headers
#include <Transports/Seatrac/MsgTypes.hpp>

using namespace std;
using namespace Transports::Seatrac;

namespace Simulators
{
  namespace USBL
  {
    using DUNE_NAMESPACES;

    //! Seatrac data structure.
    struct DataSeatrac
    {
      // Status message.
      CidStatusMsg cid_status_msg;
      // Calibration message
      CidCalAction cid_cal_action;
      CidCalActionMsg cid_cal_action_msg;  
      // Ping protocol messages.
      CidPingRequestMsg  cid_ping_req_msg;
      CidPingSendMsg  cid_ping_send_msg;
      CidPingRespMsg cid_ping_resp_msg;
      CidPingErrorMsg cid_ping_error_msg;
      // Data protocol messages.
      CidDatReceiveMsg cid_dat_receive_msg;
      CidDatSendMsg  cid_dat_send_msg;
      // Configuration protocol messages.
      CidSysInfo cid_sys_info;
      CidSettingsMsg cid_settings_msg;
      CidSysReboot cid_sys_reboot;
      CidSysRebootMsg cid_sys_reboot_msg;
      CidSettingsSetMsg cid_sys_settings_set_msg;
      CidSettingsSaveMsg cid_settings_save_msg;
      // Navigation protocol messages.
      CidXcvrFixMsg  cid_xcvr_fix_msg;
      CidNavQueryReqMsg cid_nav_query_req_msg;
      CidNavQuerySendMsg cid_nav_query_send_msg;
      CidNavQuerryRespMsg cid_nav_querry_resp_msg;
      CidNavBeaconPosUpdateMsg cid_nav_beacon_pos_update_msg;
      CidNavBeaconPosSendMsg cid_nav_beacon_pos_send_msg;
      CidNavRefPosSendMsg  cid_nav_ref_pos_send_msg;
      CidNavRefPosUpdateMsg  cid_nav_ref_pos_update_msg;
      // USBL status message
      CidXcvrUsblMsg cid_xcvr_usbl_msg;
      // aco_fix
      Acofix_t ACO_seatrac;
      uint8_t new_message[MESSAGE_NUMBER];
      std::string data_message;

      // Simulated beacon parameters
      uint8_t beacon_ID;     // Beacon identification (1 to 15)
      uint8_t beacon_state;  // Busy, cancelled, etc

      //! Constructor.
      DataSeatrac(void)
      {
        cid_dat_send_msg.lock_flag = 0;
        cid_dat_receive_msg.data_rec_flag = 0;
        for (int i = 0; i < MESSAGE_NUMBER; i++)
          new_message[i] = 0;
      }

      //! Set when new message is received.
      //! @param[in] setdata type of msg that was received.
      void
      set(CommandID setdata)
      {
        new_message[setdata] = 1;
      }

      //! Verify if new message was received.
      //! @param[in] setdata type of msg that was received.
      //! @return true if was received new message and flag is clean.
      uint8_t
      newDataAvailable(unsigned setdata)
      {
        if (setdata < MESSAGE_NUMBER)
        {
          if (new_message[setdata] == 1)
          {
            new_message[setdata] = 0;
            return 1;
          }
        }

        return 0;
      }
    };

    //! Extract data to an Acofix_t structure.
    //! @param[out] aco_fix pointer hwre data is stored.
    //! @param[in] ind raw messagem index.
    //! @param[in] msg_raw pointer to raw message.
    uint16_t
    updateEcoFix(Acofix_t* aco_fix, uint16_t ind, const char* msg_raw)
    {
      std::memcpy(&(*aco_fix).dest_id, msg_raw + ind, 1);
      std::memcpy(&(*aco_fix).src_id, msg_raw + ind + 1, 1);
      std::memcpy(&(*aco_fix).flags, msg_raw + ind + 2, 1);
      std::memcpy(&(*aco_fix).amsgtype_e, msg_raw + ind + 3, 1);
      std::memcpy(&(*aco_fix).attitude_yaw, msg_raw + ind + 4, 2);
      std::memcpy(&(*aco_fix).attitude_pitch, msg_raw + ind + 6, 2);
      std::memcpy(&(*aco_fix).attitude_roll, msg_raw + ind + 8, 2);
      std::memcpy(&(*aco_fix).depth_local, msg_raw + ind + 10, 2);
      std::memcpy(&(*aco_fix).vos, msg_raw + ind + 12, 2);
      std::memcpy(&(*aco_fix).rssi, msg_raw + ind + 14, 2);
      aco_fix->outputFlagsComp();
      ind += 16;

      // Range fields.
      if (aco_fix->outputflags_list[0])
      {
        std::memcpy(&(*aco_fix).range_count, msg_raw + ind, 4);
        std::memcpy(&(*aco_fix).range_time, msg_raw + ind + 4, 4);
        std::memcpy(&(*aco_fix).range_dist, msg_raw + ind + 8, 2);
        ind += 10;
      }

      // USBL Fields.
      if (aco_fix->outputflags_list[1])
      {
        std::memcpy(&(*aco_fix).usbl_channels, msg_raw + ind, 1);

        int i;
        aco_fix->usbl_rssi.reserve(aco_fix->usbl_channels);
        for (i = 0; i < aco_fix->usbl_channels; i++)
          std::memcpy(&(*aco_fix).usbl_rssi[i], msg_raw + ind + 1 + 2 * i, 2);

        std::memcpy(&(*aco_fix).usbl_azimuth, msg_raw + ind + 1 + 2 * i, 2);
        std::memcpy(&(*aco_fix).usbl_elevation, msg_raw + ind + 3 + 2 * i, 2);
        std::memcpy(&(*aco_fix).usbl_fit_error, msg_raw + ind + 5 + 2 * i, 2);
        ind += (7 + i * 2);
      }

      // Position Fields.
      if (aco_fix->outputflags_list[2])
      {
        std::memcpy(&(*aco_fix).position_easting, msg_raw + ind, 2);
        std::memcpy(&(*aco_fix).position_northing, msg_raw + ind + 2, 2);
        std::memcpy(&(*aco_fix).position_depth, msg_raw + ind + 4, 2);
        ind += 6;
      }

      return ind;
    }

    //! Parse received response and extract to DataSeatrac data structure.
    //! @param[in] message_type type of msessage to decode.
    //! @param[in] msg_raw raw messagem received by uart
    //! @param[out] data_Beacon pointer where the data is stored.
    void
    parseResponse(uint16_t message_type, const char* msg_raw, DataSeatrac& data_Beacon)
    {
      uint16_t ind = 0;

      switch (message_type)
      {
        case CID_STATUS:
          data_Beacon.set(CID_STATUS);
          std::memcpy(&data_Beacon.cid_status_msg.output_flags, msg_raw, 1);
          data_Beacon.cid_status_msg.outputFlagsComp();
          std::memcpy(&data_Beacon.cid_status_msg.timestamp, msg_raw + 1, 8);
          ind = 9;

          // Environment.
          if (data_Beacon.cid_status_msg.outputflags_list[0])
          {
            std::memcpy(&data_Beacon.cid_status_msg.environment_supply, msg_raw + ind, 2);
            std::memcpy(&data_Beacon.cid_status_msg.environment_temperature,
                        msg_raw + ind + 2, 2);
            std::memcpy(&data_Beacon.cid_status_msg.environment_pressure,
                        msg_raw + ind + 4, 4);
            std::memcpy(&data_Beacon.cid_status_msg.EnvironmentDepth, msg_raw + ind + 8, 4);
            std::memcpy(&data_Beacon.cid_status_msg.EnvironmentVos, msg_raw + ind + 12, 2);
            ind += 14;
          }

          // Attitude.
          if (data_Beacon.cid_status_msg.outputflags_list[1])
          {
            std::memcpy(&data_Beacon.cid_status_msg.attitude_yaw, msg_raw + ind, 2);
            std::memcpy(&data_Beacon.cid_status_msg.attitude_pitch, msg_raw + ind + 2, 2);
            std::memcpy(&data_Beacon.cid_status_msg.attitude_roll, msg_raw + ind + 4, 2);
            ind += 6;
          }

          // Mag cal.
          if (data_Beacon.cid_status_msg.outputflags_list[2])
          {
            std::memcpy(&data_Beacon.cid_status_msg.mag_cal_buf, msg_raw + ind, 1);
            std::memcpy(&data_Beacon.cid_status_msg.mag_cal_valid, msg_raw + ind  + 1, 1);
            std::memcpy(&data_Beacon.cid_status_msg.mag_cal_age, msg_raw + ind  + 2, 4);
            std::memcpy(&data_Beacon.cid_status_msg.mag_cal_fit, msg_raw + ind  + 6, 1);
            ind += 7;
          }

          // Acc cal.
          if (data_Beacon.cid_status_msg.outputflags_list[3])
          {
            std::memcpy(&data_Beacon.cid_status_msg.acc_lim_min_y, msg_raw + ind, 2);
            std::memcpy(&data_Beacon.cid_status_msg.acc_lim_min_z, msg_raw + ind + 2, 2);
            std::memcpy(&data_Beacon.cid_status_msg.acc_lim_min_x, msg_raw + ind + 4, 2);
            std::memcpy(&data_Beacon.cid_status_msg.acc_lim_max_x, msg_raw + ind + 6, 2);
            std::memcpy(&data_Beacon.cid_status_msg.acc_lim_max_y, msg_raw + ind + 8, 2);
            std::memcpy(&data_Beacon.cid_status_msg.acc_lim_max_z, msg_raw + ind + 10, 2);
            ind += 12;
          }

          // AHRS raw data.
          if (data_Beacon.cid_status_msg.outputflags_list[4])
          {
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_acc_x, msg_raw + ind, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_acc_y, msg_raw + ind + 2, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_acc_z, msg_raw + ind + 4, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_mag_x, msg_raw + ind + 6, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_mag_y, msg_raw + ind + 8, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_mag_z, msg_raw + ind + 10, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_gyro_x, msg_raw + ind + 12, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_gyro_y, msg_raw + ind + 14, 2);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_raw_gyro_z, msg_raw + ind + 16, 2);
            ind += 18;
          }

          // AHRS computed data.
          if (data_Beacon.cid_status_msg.outputflags_list[5])
          {
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_acc_x, msg_raw + ind, 4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_acc_y, msg_raw + ind + 4, 4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_acc_z, msg_raw + ind + 8, 4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_mag_x, msg_raw + ind + 12,4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_mag_y, msg_raw + ind + 16,4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_mag_z, msg_raw + ind + 20,4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_gyro_x, msg_raw + ind + 24,4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_gyro_y, msg_raw + ind + 28,4);
            std::memcpy(&data_Beacon.cid_status_msg.ahrs_comp_gyro_z, msg_raw + ind + 32,4);
          }
          break;

        case CID_PING_REQ:
          data_Beacon.set(CID_PING_REQ);
          ind = updateEcoFix(&data_Beacon.cid_ping_req_msg.aco_fix, ind, msg_raw);
          break;

        case CID_PING_RESP:  // Message sent when a PING response is received.
          data_Beacon.set(CID_PING_RESP);
          ind = updateEcoFix(&data_Beacon.cid_ping_resp_msg.aco_fix, ind, msg_raw);
          break;

        case CID_PING_ERROR:
          data_Beacon.set(CID_PING_ERROR);
          std::memcpy(&data_Beacon.cid_ping_error_msg.status, msg_raw + ind, 1);
          std::memcpy(&data_Beacon.cid_ping_error_msg.beacon_id, msg_raw + ind + 1, 1);
          break;

        case CID_PING_SEND:
          data_Beacon.set(CID_PING_SEND);
          std::memcpy(&data_Beacon.cid_ping_send_msg.status, msg_raw + ind, 1);
          std::memcpy(&data_Beacon.cid_ping_send_msg.beacon_id, msg_raw + ind + 1, 1);
          break;

        case CID_DAT_SEND:
          data_Beacon.set(CID_DAT_SEND);
          std::memcpy(&data_Beacon.cid_dat_send_msg.status, msg_raw + ind, 1);
          std::memcpy(&data_Beacon.cid_dat_send_msg.beacon_id, msg_raw + ind + 1, 1);
          break;

        case CID_DAT_RECEIVE:
          ind = updateEcoFix(&data_Beacon.cid_dat_receive_msg.aco_fix, ind, msg_raw);
          std::memcpy(&data_Beacon.cid_dat_receive_msg.ack_flag, msg_raw + ind, 1);
          std::memcpy(&data_Beacon.cid_dat_receive_msg.packet_len, msg_raw + ind +1, 1);
          ind += 2;
          for (int i = 0; i < data_Beacon.cid_dat_receive_msg.packet_len; i++)
          {
            std::memcpy(&data_Beacon.cid_dat_receive_msg.packet_data[i],
                        msg_raw + ind  + i, 1);
          }
          data_Beacon.set(CID_DAT_RECEIVE);
          break;

        case CID_DAT_ERROR:
          data_Beacon.set(CID_DAT_ERROR);
          std::memcpy(&data_Beacon.cid_dat_send_msg.status, msg_raw, 1);
          std::memcpy(&data_Beacon.cid_dat_send_msg.beacon_id, msg_raw + 1, 1);
          break;

        case CID_SETTINGS_GET:
          data_Beacon.set(CID_SETTINGS_GET);
          std::memcpy(&data_Beacon.cid_settings_msg.status_flags, msg_raw, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.status_output, msg_raw + 1, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.uart_main_baud, msg_raw + 2, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.uart_aux_baud, msg_raw + 3, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.net_mac_addr.bytes, msg_raw + 4, 6);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_addr.bytes, msg_raw + 10, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_subnet.bytes, msg_raw + 14, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_gateway.bytes, msg_raw + 18, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_dns.bytes, msg_raw + 22, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_tcp_port, msg_raw + 26, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.env_flags, msg_raw + 28, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.env_pressure_ofs, msg_raw + 29, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.env_salinity, msg_raw + 33, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.env_vos, msg_raw + 35, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_flags, msg_raw + 37, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_min_x, msg_raw + 38, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_min_y, msg_raw + 40, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_min_z, msg_raw + 42, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_max_x, msg_raw + 44, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_max_y, msg_raw + 46, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_max_z, msg_raw + 48, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_valid, msg_raw + 50, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_x, msg_raw + 51, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_y, msg_raw + 55, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_z, msg_raw + 59, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_x, msg_raw + 63, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_y, msg_raw + 67, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_z, msg_raw + 71, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_field, msg_raw + 75, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_error, msg_raw + 79, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_x, msg_raw + 83, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_y, msg_raw + 85, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_z, msg_raw + 87, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_yaw_ofs, msg_raw + 89, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_pitch_ofs, msg_raw + 91, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_roll_ofs, msg_raw + 93, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_flags, msg_raw + 95, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_beacon_id, msg_raw + 96, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_range_tmo, msg_raw + 97, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_resp_time, msg_raw + 99, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_yaw, msg_raw + 101, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_pitch, msg_raw + 103, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_roll, msg_raw + 105, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_posflt_vel, msg_raw + 107, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_posflt_ang, msg_raw + 108, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_posflt_tmo, msg_raw + 109, 1);
          break;

        case  CID_NAV_QUERY_REQ:
          data_Beacon.set(CID_NAV_QUERY_REQ);
          ind = updateEcoFix(&data_Beacon.cid_nav_query_req_msg.aco_fix, ind, msg_raw);
          std::memcpy(&data_Beacon.cid_nav_query_req_msg.nav_query_t, msg_raw + ind, 1);
          break;

        case  CID_XCVR_FIX:
          data_Beacon.set(CID_XCVR_FIX);
          ind = updateEcoFix(&data_Beacon.cid_xcvr_fix_msg.aco_fix, ind, msg_raw);
          break;

        case CID_NAV_QUERY_RESP:
          data_Beacon.set(CID_NAV_QUERY_RESP);
          ind = updateEcoFix(&data_Beacon.cid_nav_querry_resp_msg.aco_fix, ind, msg_raw);
          std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.query_flags, msg_raw + ind, 1);
          ind += 1;
          data_Beacon.cid_nav_querry_resp_msg.queryFlagsExtract();

          if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[0])
          {
            std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_depth, msg_raw + ind,4);
            ind += 4;
          }

          if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[1])
          {
            std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_supply, msg_raw + ind, 2);
            ind += 2;
          }

          if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[2])
          {
            std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_temp, msg_raw + ind, 2);
            ind += 2;
          }

          if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[3])
          {
            std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_yaw, msg_raw + ind, 2);
            std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_pitch,
                        msg_raw + ind + 2, 2);
            std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_roll,
                        msg_raw + ind + 4, 2);
          }
          break;

        case  CID_SYS_REBOOT:
          std::memcpy(&data_Beacon.cid_sys_reboot_msg.status, msg_raw, 1);
          break;

        case  CID_SETTINGS_SAVE:
          std::memcpy(&data_Beacon.cid_settings_save_msg.status, msg_raw, 1);
          break;

        case CID_NAV_QUERY_SEND:
          std::memcpy(&data_Beacon.cid_nav_query_send_msg.status, msg_raw, 1);
          break;

        case CID_NAV_BEACON_POS_UPDATE:
          data_Beacon.set(CID_NAV_BEACON_POS_UPDATE);
          ind = updateEcoFix(&data_Beacon.cid_nav_beacon_pos_update_msg.aco_fix, ind, msg_raw);
          std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.beacon_id, msg_raw + ind, 1);
          std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_easting,
                      msg_raw + ind + 1, 2);
          std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_northing,
                      msg_raw + ind + 3, 2);
          std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_depth,
                      msg_raw + ind + 5, 2);
          break;

        case CID_NAV_BEACON_POS_SEND:
          std::memcpy(&data_Beacon.cid_nav_beacon_pos_send_msg.status, msg_raw, 1);
          break;

        case CID_NAV_REF_POS_SEND:
          std::memcpy(&data_Beacon.cid_nav_ref_pos_send_msg.status, msg_raw,1);
          break;

        case CID_NAV_REF_POS_UPDATE:
          data_Beacon.set(CID_NAV_REF_POS_UPDATE);
          ind = updateEcoFix(&data_Beacon.cid_nav_ref_pos_update_msg.aco_fix, ind, msg_raw);
          std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.beacon_id, msg_raw + ind, 1);
          std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.position_latitude,
                      msg_raw + ind + 1, 4);
          std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.position_longitude,
                      msg_raw + ind + 5, 4);
          break;

        case CID_SYS_INFO:
          data_Beacon.set(CID_SYS_INFO);
          std::memcpy(&data_Beacon.cid_sys_info.seconds, msg_raw + 0, 4);
          std::memcpy(&data_Beacon.cid_sys_info.section, msg_raw + 4, 1);
          std::memcpy(&data_Beacon.cid_sys_info.hardware.part_number, msg_raw + 5, 2);
          std::memcpy(&data_Beacon.cid_sys_info.hardware.part_rev, msg_raw + 7, 1);
          std::memcpy(&data_Beacon.cid_sys_info.hardware.serial_number, msg_raw + 8, 4);
          std::memcpy(&data_Beacon.cid_sys_info.hardware.flags_sys, msg_raw + 12, 2);
          std::memcpy(&data_Beacon.cid_sys_info.hardware.flags_user, msg_raw + 14, 2);
          std::memcpy(&data_Beacon.cid_sys_info.boot_firmware.valid, msg_raw + 16, 1);
          std::memcpy(&data_Beacon.cid_sys_info.boot_firmware.part_number, msg_raw + 17, 2);
          std::memcpy(&data_Beacon.cid_sys_info.boot_firmware.version_maj, msg_raw + 19, 1);
          std::memcpy(&data_Beacon.cid_sys_info.boot_firmware.version_min, msg_raw + 20, 1);
          std::memcpy(&data_Beacon.cid_sys_info.boot_firmware.version_build, msg_raw + 21, 2);
          std::memcpy(&data_Beacon.cid_sys_info.boot_firmware.checksum, msg_raw + 23, 4);
          std::memcpy(&data_Beacon.cid_sys_info.main_firmware.valid, msg_raw + 27, 1);
          std::memcpy(&data_Beacon.cid_sys_info.main_firmware.part_number, msg_raw + 28, 2);
          std::memcpy(&data_Beacon.cid_sys_info.main_firmware.version_maj, msg_raw + 30, 1);
          std::memcpy(&data_Beacon.cid_sys_info.main_firmware.version_min, msg_raw + 31, 1);
          std::memcpy(&data_Beacon.cid_sys_info.main_firmware.version_build, msg_raw + 33, 2);
          std::memcpy(&data_Beacon.cid_sys_info.main_firmware.checksum, msg_raw + 35, 4);
          break;

        case CID_XCVR_USBL:
          data_Beacon.set(CID_XCVR_USBL);
          ind = ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_sig_peak, (const uint8_t*)msg_raw);
          ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_threshold, (const uint8_t*)&msg_raw[ind]);
          ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_cross_point, (const uint8_t*)&msg_raw[ind]);
          ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_cross_mag, (const uint8_t*)&msg_raw[ind]);
          ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_detect, (const uint8_t*)&msg_raw[ind]);
          ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_length, (const uint8_t*)&msg_raw[ind]);

          data_Beacon.cid_xcvr_usbl_msg.xcor_data.reserve(data_Beacon.cid_xcvr_usbl_msg.xcor_length);
          for(uint16_t i = 0; i < data_Beacon.cid_xcvr_usbl_msg.xcor_length; i++)
          {
            ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_data[i], (const uint8_t*)&msg_raw[ind]);
          }

          data_Beacon.cid_xcvr_usbl_msg.channels = msg_raw[ind++];
          data_Beacon.cid_xcvr_usbl_msg.channel_rssi.reserve(data_Beacon.cid_xcvr_usbl_msg.channels);
          for(uint16_t i = 0; i < data_Beacon.cid_xcvr_usbl_msg.channels; i++)
          {
            ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.channel_rssi[i], (const uint8_t*)&msg_raw[ind]);
          }

          data_Beacon.cid_xcvr_usbl_msg.baselines = msg_raw[ind++];
          data_Beacon.cid_xcvr_usbl_msg.phase_angle.reserve(data_Beacon.cid_xcvr_usbl_msg.baselines);
          for(uint16_t i = 0; i < data_Beacon.cid_xcvr_usbl_msg.baselines; i++)
          {
            ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.phase_angle[i], (const uint8_t*)&msg_raw[ind]);
          }
          ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.signal_azimuth, (const uint8_t*)&msg_raw[ind]);
          ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.signal_elevation, (const uint8_t*)&msg_raw[ind]);
          ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.signal_fit_error, (const uint8_t*)&msg_raw[ind]);
          break;

          // Should never get here.
        default:
          //m_data_state = DP_COMPLETE;
          break;
      }
    }

    //! Parse command received to populate DataSeatrac data structure.
    //! @param[in] message_type type of msessage to decode.
    //! @param[in] msg_raw raw messagem received by uart
    //! @param[out] data_Beacon pointer where the data is stored.
    void
    parseCommand(uint16_t message_type, const char* msg_raw, DataSeatrac& data_Beacon)
    {
      switch (message_type)
      {
        case CID_STATUS:
          data_Beacon.set(CID_STATUS);
          std::memcpy(&data_Beacon.cid_status_msg.output_flags, msg_raw, 1);
          data_Beacon.cid_status_msg.outputFlagsComp();
          break;
        
        case CID_CAL_ACTION:
          data_Beacon.set(CID_CAL_ACTION);
          std::memcpy(&data_Beacon.cid_cal_action.action, msg_raw, 1);
          break;

        case CID_SETTINGS_SET:
          data_Beacon.set(CID_SETTINGS_SET);
          std::memcpy(&data_Beacon.cid_settings_msg.status_flags, msg_raw, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.status_output, msg_raw + 1, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.uart_main_baud, msg_raw + 2, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.uart_aux_baud, msg_raw + 3, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.net_mac_addr.bytes, msg_raw + 4, 6);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_addr.bytes, msg_raw + 10, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_subnet.bytes, msg_raw + 14, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_gateway.bytes, msg_raw + 18, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_ip_dns.bytes, msg_raw + 22, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.net_tcp_port, msg_raw + 26, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.env_flags, msg_raw + 28, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.env_pressure_ofs, msg_raw + 29, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.env_salinity, msg_raw + 33, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.env_vos, msg_raw + 35, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_flags, msg_raw + 37, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_min_x, msg_raw + 38, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_min_y, msg_raw + 40, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_min_z, msg_raw + 42, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_max_x, msg_raw + 44, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_max_y, msg_raw + 46, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.acc_max_z, msg_raw + 48, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_valid, msg_raw + 50, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_x, msg_raw + 51, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_y, msg_raw + 55, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_z, msg_raw + 59, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_x, msg_raw + 63, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_y, msg_raw + 67, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_z, msg_raw + 71, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_field, msg_raw + 75, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.mag_error, msg_raw + 79, 4);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_x, msg_raw + 83, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_y, msg_raw + 85, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_z, msg_raw + 87, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_yaw_ofs, msg_raw + 89, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_pitch_ofs, msg_raw + 91, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.ahrs_roll_ofs, msg_raw + 93, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_flags, msg_raw + 95, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_beacon_id, msg_raw + 96, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_range_tmo, msg_raw + 97, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_resp_time, msg_raw + 99, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_yaw, msg_raw + 101, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_pitch, msg_raw + 103, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_roll, msg_raw + 105, 2);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_posflt_vel, msg_raw + 107, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_posflt_ang, msg_raw + 108, 1);
          std::memcpy(&data_Beacon.cid_settings_msg.xcvr_posflt_tmo, msg_raw + 109, 1);
          break;

        case CID_PING_REQ:
          data_Beacon.set(CID_PING_REQ);
          // No command fields
          break;

        case CID_PING_RESP:  // Message sent when a PING response is received.
          data_Beacon.set(CID_PING_RESP);
          // No command fields
          break;

        case CID_PING_ERROR:
          data_Beacon.set(CID_PING_ERROR);
          // No command fields
          break;

        case CID_PING_SEND:
          data_Beacon.set(CID_PING_SEND);
          std::memcpy(&data_Beacon.cid_ping_send_msg.dest_id, msg_raw, 1);
          std::memcpy(&data_Beacon.cid_ping_send_msg.msg_type, msg_raw + 1, 1);
          break;

        case CID_DAT_SEND:
          data_Beacon.set(CID_DAT_SEND);
          std::memcpy(&data_Beacon.cid_dat_send_msg.dest_id, msg_raw, 1);
          std::memcpy(&data_Beacon.cid_dat_send_msg.beacon_id, msg_raw + 1, 1);
          std::memcpy(&data_Beacon.cid_dat_send_msg.msg_type, msg_raw + 2, 1);
          std::memcpy(&data_Beacon.cid_dat_send_msg.packet_len, msg_raw + 3, 2);
          for (int i = 0; i < data_Beacon.cid_dat_receive_msg.packet_len; i++)
          {
            std::memcpy(&data_Beacon.cid_dat_receive_msg.packet_data[i],
                        msg_raw + 3 + i, 1);
          }
          break;

        case CID_DAT_RECEIVE:
          data_Beacon.set(CID_DAT_RECEIVE);
          // No command to parse
          break;

        case CID_DAT_ERROR:
          data_Beacon.set(CID_DAT_ERROR);
          // No command to parse
          break;

        case CID_SETTINGS_GET:
          data_Beacon.set(CID_SETTINGS_GET);
          // Nothing to parse
          break;

        case  CID_NAV_QUERY_REQ:
          data_Beacon.set(CID_NAV_QUERY_REQ);
          // No command to parse
          break;

        case  CID_XCVR_FIX:
          data_Beacon.set(CID_XCVR_FIX);
          // No command to parse
          break;

        case CID_NAV_QUERY_RESP:
          data_Beacon.set(CID_NAV_QUERY_RESP);
          // No command to parse 
          break;

        case  CID_SYS_REBOOT:
          data_Beacon.set(CID_SYS_REBOOT);
          std::memcpy(&data_Beacon.cid_sys_reboot.check, msg_raw, 4);
          break;

        case  CID_SETTINGS_SAVE:
          data_Beacon.set(CID_SETTINGS_SAVE);
          // Nothing to parse
          break;

        case CID_NAV_QUERY_SEND:
          data_Beacon.set(CID_NAV_QUERY_SEND);
          std::memcpy(&data_Beacon.cid_nav_query_send_msg.dest_id, msg_raw, 1);
          std::memcpy(&data_Beacon.cid_nav_query_send_msg.query_flags, msg_raw + 1, 2);
          std::memcpy(&data_Beacon.cid_nav_query_send_msg.packet_len, msg_raw + 3, 2);
          for (int i = 0; i < data_Beacon.cid_nav_query_send_msg.packet_len; i++)
          {
            std::memcpy(&data_Beacon.cid_nav_query_send_msg.packet_data[i],
                        msg_raw + 3 + i, 1);
          }
          break;

        // Deprecated
        // case CID_NAV_BEACON_POS_UPDATE:
        //   data_Beacon.set(CID_NAV_BEACON_POS_UPDATE);
        //   ind = updateEcoFix(&data_Beacon.cid_nav_beacon_pos_update_msg.aco_fix, ind, msg_raw);
        //   std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.beacon_id, msg_raw + ind, 1);
        //   std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_easting,
        //               msg_raw + ind + 1, 2);
        //   std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_northing,
        //               msg_raw + ind + 3, 2);
        //   std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_depth,
        //               msg_raw + ind + 5, 2);
        //   break;

        // Deprecated
        // case CID_NAV_BEACON_POS_SEND:
        //   std::memcpy(&data_Beacon.cid_nav_beacon_pos_send_msg.status, msg_raw, 1);
        //   break;

        // Deprecated
        // case CID_NAV_REF_POS_SEND:
        //   std::memcpy(&data_Beacon.cid_nav_ref_pos_send_msg.status, msg_raw,1);
        //   break;

        // Deprecated
        // case CID_NAV_REF_POS_UPDATE:
        //   data_Beacon.set(CID_NAV_REF_POS_UPDATE);
        //   ind = updateEcoFix(&data_Beacon.cid_nav_ref_pos_update_msg.aco_fix, ind, msg_raw);
        //   std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.beacon_id, msg_raw + ind, 1);
        //   std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.position_latitude,
        //               msg_raw + ind + 1, 4);
        //   std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.position_longitude,
        //               msg_raw + ind + 5, 4);
        //   break;

        case CID_SYS_INFO:
          data_Beacon.set(CID_SYS_INFO);
          // Nothing to parse
          break;

        case CID_XCVR_USBL:
          data_Beacon.set(CID_XCVR_USBL);
          // No command to parse
          break;

          // Should never get here.
        default:
          //m_data_state = DP_COMPLETE;
          break;
      }
    }

    //! Creates a response for the acoustic modem.
    //! @param[in] cid_type type of message.
    //! @param[in] data_Beacon message structure.
    //! @return string with the response.
    std::string
    responseCreateSeatrac(uint16_t cid_type, DataSeatrac& data_Beacon)
    {
      std::string cmd = "$";
      std::string check_sum;
      std::string message_build = String::str("%02X",(uint16_t) cid_type);
      std::string tmp;

      switch (cid_type)
      {
        case CID_STATUS:
        {
          // Status messages are automatically generated, so this will be sent periodically
          std::vector<char> msg_temp(99, 0);
          std::memcpy(&msg_temp[0], &data_Beacon.cid_status_msg.output_flags, 1);
          std::memcpy(&msg_temp[1], &data_Beacon.cid_status_msg.timestamp, 8);

          // Environment.
          if (data_Beacon.cid_status_msg.outputflags_list[0])
          {
            std::memcpy(&msg_temp[9], &data_Beacon.cid_status_msg.environment_supply, 2);
            std::memcpy(&msg_temp[11], &data_Beacon.cid_status_msg.environment_temperature, 2);
            std::memcpy(&msg_temp[13], &data_Beacon.cid_status_msg.environment_pressure, 4);
            std::memcpy(&msg_temp[19], &data_Beacon.cid_status_msg.EnvironmentDepth, 4);
            std::memcpy(&msg_temp[21], &data_Beacon.cid_status_msg.EnvironmentVos, 2);
          }

          // Attitude.
          if (data_Beacon.cid_status_msg.outputflags_list[1])
          {
            std::memcpy(&msg_temp[23], &data_Beacon.cid_status_msg.attitude_yaw, 2);
            std::memcpy(&msg_temp[25], &data_Beacon.cid_status_msg.attitude_pitch, 2);
            std::memcpy(&msg_temp[27], &data_Beacon.cid_status_msg.attitude_roll, 2);
          }

          // Mag cal.
          if (data_Beacon.cid_status_msg.outputflags_list[2])
          {
            std::memcpy(&msg_temp[29], &data_Beacon.cid_status_msg.mag_cal_buf, 1);
            std::memcpy(&msg_temp[30], &data_Beacon.cid_status_msg.mag_cal_valid, 1);
            std::memcpy(&msg_temp[31], &data_Beacon.cid_status_msg.mag_cal_age, 4);
            std::memcpy(&msg_temp[35], &data_Beacon.cid_status_msg.mag_cal_fit, 1);
          }

          // Acc cal.
          if (data_Beacon.cid_status_msg.outputflags_list[3])
          {
            std::memcpy(&msg_temp[36], &data_Beacon.cid_status_msg.acc_lim_min_y, 2);
            std::memcpy(&msg_temp[38], &data_Beacon.cid_status_msg.acc_lim_min_z, 2);
            std::memcpy(&msg_temp[40], &data_Beacon.cid_status_msg.acc_lim_min_x, 2);
            std::memcpy(&msg_temp[42], &data_Beacon.cid_status_msg.acc_lim_max_x, 2);
            std::memcpy(&msg_temp[44], &data_Beacon.cid_status_msg.acc_lim_max_y, 2);
            std::memcpy(&msg_temp[46], &data_Beacon.cid_status_msg.acc_lim_max_z, 2);
          }

          // AHRS raw data.
          if (data_Beacon.cid_status_msg.outputflags_list[4])
          {
            std::memcpy(&msg_temp[48], &data_Beacon.cid_status_msg.ahrs_raw_acc_x, 2);
            std::memcpy(&msg_temp[50], &data_Beacon.cid_status_msg.ahrs_raw_acc_y, 2);
            std::memcpy(&msg_temp[52], &data_Beacon.cid_status_msg.ahrs_raw_acc_z, 2);
            std::memcpy(&msg_temp[54], &data_Beacon.cid_status_msg.ahrs_raw_mag_x, 2);
            std::memcpy(&msg_temp[56], &data_Beacon.cid_status_msg.ahrs_raw_mag_y, 2);
            std::memcpy(&msg_temp[58], &data_Beacon.cid_status_msg.ahrs_raw_mag_z, 2);
            std::memcpy(&msg_temp[60], &data_Beacon.cid_status_msg.ahrs_raw_gyro_x, 2);
            std::memcpy(&msg_temp[62], &data_Beacon.cid_status_msg.ahrs_raw_gyro_y, 2);
            std::memcpy(&msg_temp[64], &data_Beacon.cid_status_msg.ahrs_raw_gyro_z, 2);
          }

          // AHRS computed data.
          if (data_Beacon.cid_status_msg.outputflags_list[5])
          {
            std::memcpy(&msg_temp[66], &data_Beacon.cid_status_msg.ahrs_comp_acc_x, 4);
            std::memcpy(&msg_temp[70], &data_Beacon.cid_status_msg.ahrs_comp_acc_y, 4);
            std::memcpy(&msg_temp[74], &data_Beacon.cid_status_msg.ahrs_comp_acc_z, 4);
            std::memcpy(&msg_temp[78], &data_Beacon.cid_status_msg.ahrs_comp_mag_x, 4);
            std::memcpy(&msg_temp[82], &data_Beacon.cid_status_msg.ahrs_comp_mag_y, 4);
            std::memcpy(&msg_temp[86], &data_Beacon.cid_status_msg.ahrs_comp_mag_z, 4);
            std::memcpy(&msg_temp[90], &data_Beacon.cid_status_msg.ahrs_comp_gyro_x, 4);
            std::memcpy(&msg_temp[94], &data_Beacon.cid_status_msg.ahrs_comp_gyro_y, 4);
            std::memcpy(&msg_temp[98], &data_Beacon.cid_status_msg.ahrs_comp_gyro_z, 4);
          }
          message_build += String::toHex(msg_temp);
          break;
        }

        case CID_PING_SEND:
        {
          // When destination ID parameter is invalid or missing
          // NOTE: CST_CMD_PARAM_INVALID and CST_CMD_PARAM_MISSING have practically the same
          // logical effect
          if (   data_Beacon.cid_ping_send_msg.dest_id < 1
              || data_Beacon.cid_ping_send_msg.dest_id > 15) {
            message_build += String::str("%02X", Transports::Seatrac::CST_CMD_PARAM_INVALID);
          } 
          // When modem is busy
          else if (data_Beacon.beacon_state == IMC::UamTxStatus::UTS_BUSY){
            message_build += String::str("%02X", CST_XCVR_BUSY);
          }
          else {
            message_build += String::str("%02X", CST_OK);
          }
          break;
        }

        case CID_DAT_SEND:
        {
          // When destination ID parameter is invalid or missing
          // NOTE: CST_CMD_PARAM_INVALID and CST_CMD_PARAM_MISSING have practically the same
          // logical effect
          if (   data_Beacon.cid_ping_send_msg.dest_id < 0x01
              || data_Beacon.cid_ping_send_msg.dest_id > 0x0F) {
            message_build += String::str("%02X", CST_CMD_PARAM_INVALID);
          } 
          // When modem is busy
          else if (data_Beacon.beacon_state == IMC::UamTxStatus::UTS_BUSY){
            message_build += String::str("%02X", CST_XCVR_BUSY);
          }
          else {
            message_build += String::str("%02X", CST_OK);
          }
          message_build += String::str("%02X", data_Beacon.beacon_ID);
          break;
        }
        
        case CID_CAL_ACTION:
        {
          // CAL_ACTION_E goes from 0 to 7 (unsigned), if more than 7 then the value is invalid
          if (data_Beacon.cid_cal_action.action > Transports::Seatrac::CAL_PRES_OFFSET_CALC)
          {
            message_build += String::str("%02X", Transports::Seatrac::CST_CMD_PARAM_MISSING);
          } else {
            message_build += String::str("%02X", Transports::Seatrac::CST_OK);
          }
          break;
        }

        case CID_SETTINGS_SET:
        {
          // As we don't know what kind of checks the beacon performs on the settings,
          // we assume everything went fine
          message_build += String::str("%02X", CST_OK);
          break;
        }

        case CID_SETTINGS_GET:
        {
          std::vector<char> msg_temp(110, 0);
          std::memcpy(&msg_temp[0], &data_Beacon.cid_settings_msg.status_flags, 1);
          std::memcpy(&msg_temp[1], &data_Beacon.cid_settings_msg.status_output, 1);
          std::memcpy(&msg_temp[2], &data_Beacon.cid_settings_msg.uart_main_baud, 1);
          std::memcpy(&msg_temp[3], &data_Beacon.cid_settings_msg.uart_aux_baud, 1);
          std::memcpy(&msg_temp[4], &data_Beacon.cid_settings_msg.net_mac_addr.bytes, 6);
          std::memcpy(&msg_temp[10], &data_Beacon.cid_settings_msg.net_ip_addr.bytes, 4);
          std::memcpy(&msg_temp[14], &data_Beacon.cid_settings_msg.net_ip_subnet.bytes, 4);
          std::memcpy(&msg_temp[18], &data_Beacon.cid_settings_msg.net_ip_gateway.bytes, 4);
          std::memcpy(&msg_temp[22], &data_Beacon.cid_settings_msg.net_ip_dns.bytes, 4);
          std::memcpy(&msg_temp[26], &data_Beacon.cid_settings_msg.net_tcp_port, 2);
          std::memcpy(&msg_temp[28], &data_Beacon.cid_settings_msg.env_flags, 1);
          std::memcpy(&msg_temp[29], &data_Beacon.cid_settings_msg.env_pressure_ofs, 4);
          std::memcpy(&msg_temp[33], &data_Beacon.cid_settings_msg.env_salinity, 2);
          std::memcpy(&msg_temp[35], &data_Beacon.cid_settings_msg.env_vos, 2);
          std::memcpy(&msg_temp[37], &data_Beacon.cid_settings_msg.ahrs_flags, 1);
          std::memcpy(&msg_temp[38], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_x, 2);
          std::memcpy(&msg_temp[40], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_y, 2);
          std::memcpy(&msg_temp[42], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_z, 2);
          std::memcpy(&msg_temp[44], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_x, 2);
          std::memcpy(&msg_temp[46], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_y, 2);
          std::memcpy(&msg_temp[48], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_z, 2);
          std::memcpy(&msg_temp[50], &data_Beacon.cid_settings_msg.ahrs_cal.mag_valid, 1);
          std::memcpy(&msg_temp[51], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_x, 4);
          std::memcpy(&msg_temp[55], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_y, 4);
          std::memcpy(&msg_temp[59], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_z, 4);
          std::memcpy(&msg_temp[63], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_x, 4);
          std::memcpy(&msg_temp[67], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_y, 4);
          std::memcpy(&msg_temp[71], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_z, 4);
          std::memcpy(&msg_temp[75], &data_Beacon.cid_settings_msg.ahrs_cal.mag_field, 4);
          std::memcpy(&msg_temp[79], &data_Beacon.cid_settings_msg.ahrs_cal.mag_error, 4);
          std::memcpy(&msg_temp[83], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_x, 2);
          std::memcpy(&msg_temp[85], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_y, 2);
          std::memcpy(&msg_temp[87], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_z, 2);
          std::memcpy(&msg_temp[89], &data_Beacon.cid_settings_msg.ahrs_yaw_ofs, 2);
          std::memcpy(&msg_temp[91], &data_Beacon.cid_settings_msg.ahrs_pitch_ofs, 2);
          std::memcpy(&msg_temp[93], &data_Beacon.cid_settings_msg.ahrs_roll_ofs, 2);
          std::memcpy(&msg_temp[95], &data_Beacon.cid_settings_msg.xcvr_flags, 1);
          std::memcpy(&msg_temp[96], &data_Beacon.cid_settings_msg.xcvr_beacon_id, 1);
          std::memcpy(&msg_temp[97], &data_Beacon.cid_settings_msg.xcvr_range_tmo, 2);
          std::memcpy(&msg_temp[99], &data_Beacon.cid_settings_msg.xcvr_resp_time, 2);
          std::memcpy(&msg_temp[101], &data_Beacon.cid_settings_msg.xcvr_yaw, 2);
          std::memcpy(&msg_temp[103], &data_Beacon.cid_settings_msg.xcvr_pitch, 2);
          std::memcpy(&msg_temp[105], &data_Beacon.cid_settings_msg.xcvr_roll, 2);
          std::memcpy(&msg_temp[107], &data_Beacon.cid_settings_msg.xcvr_posflt_vel, 1);
          std::memcpy(&msg_temp[108], &data_Beacon.cid_settings_msg.xcvr_posflt_ang, 1);
          std::memcpy(&msg_temp[109], &data_Beacon.cid_settings_msg.xcvr_posflt_tmo, 1);
          message_build += String::toHex(msg_temp);
        }
        
        case CID_SYS_REBOOT:
          // Check must be exactly 0x956A
          if(data_Beacon.cid_sys_reboot.check != 0x6A95){
            message_build += String::str("%02X", Transports::Seatrac::CST_CMD_PARAM_INVALID);
          } else {
            // Check must be exactly 0x956A, or else it is invalid
            message_build += String::str("%02X",Transports::Seatrac::CST_OK);
          }
          break;

        // // Continue from here
        // case CID_NAV_BEACON_POS_SEND:
        // {
        //   std::vector<char> msg_temp(7, 0);
        //   std::memcpy(&msg_temp[0], &data_Beacon.cid_nav_beacon_pos_send_msg.beacon_id, 1);
        //   std::memcpy(&msg_temp[1], &data_Beacon.cid_nav_beacon_pos_send_msg.position_easting, 2);
        //   std::memcpy(&msg_temp[3],
        //               &data_Beacon.cid_nav_beacon_pos_send_msg.position_northing, 2);
        //   std::memcpy(&msg_temp[5], &data_Beacon.cid_nav_beacon_pos_send_msg.position_depth, 2);
        //   message_build += String::toHex(msg_temp);
        //   break;
        // }

        // case CID_SETTINGS_SAVE:
        //   // not require parameters.
        //   break;

        // case CID_SYS_INFO:
        //   // not require parameters.
        //   break;

        // case CID_NAV_REF_POS_SEND:
        // {
        //   std::vector<char> msg_temp(8, 0);
        //   std::memcpy(&msg_temp[0], &data_Beacon.cid_nav_ref_pos_send_msg.position_latitude, 4);
        //   std::memcpy(&msg_temp[4], &data_Beacon.cid_nav_ref_pos_send_msg.position_longitude, 4);
        //   message_build += String::toHex(msg_temp);
        //   break;
        // }
        // case CID_NAV_QUERY_SEND:
        //   message_build+= String::str("%02X%02X",
        //                               ((uint8_t)data_Beacon.cid_nav_query_send_msg.dest_id),
        //                               ((uint8_t) data_Beacon.cid_nav_query_send_msg.query_flags));
        //   break;

          // should never get here.
        default:
          break;
      }

      // Compute CRC.
      std::string msg = String::fromHex(message_build);
      const char* msg_raw = msg.data();
      uint16_t temp_crc = CRC16::compute((uint8_t*) msg_raw, msg.size(), 0);
      uint16_t crc = ((0x00ff & temp_crc) << 8) + ((0xff00 & temp_crc) >> 8);
      check_sum = String::str("%04X",(uint16_t) crc);
      // Add parameters to the message.
      cmd += message_build;
      cmd += check_sum;
      cmd += "\n\r";
      return cmd;
    }

    //! Creates a command to the modem acoustic.
    //! @param[in] cid_type type of message.
    //! @param[in] data_Beacon message structure.
    //! @return string with the command.
    std::string
    commandCreateSeatrac(CommandID cid_type, DataSeatrac& data_Beacon)
    {
      std::string cmd = "#";
      std::string check_sum;
      std::string message_build = String::str("%02X",(uint16_t) cid_type);
      std::string tmp;

      switch (cid_type)
      {
        case CID_PING_SEND:
          message_build += String::str("%02X%02X",
                                       ((uint8_t)data_Beacon.cid_ping_send_msg.dest_id),
                                       ((uint8_t)data_Beacon.cid_ping_send_msg.msg_type));
          break;

        case CID_DAT_SEND:
          message_build += String::str("%02X%02X%02X",
                                       ((uint8_t)data_Beacon.cid_dat_send_msg.dest_id),
                                       ((uint8_t)data_Beacon.cid_dat_send_msg.msg_type),
                                       ((uint8_t)data_Beacon.cid_dat_send_msg.packet_len));
          message_build += data_Beacon.cid_dat_send_msg.packet_data;
          break;
        
        case CID_CAL_ACTION:
        {
          message_build += String::str("%02X", (uint8_t)data_Beacon.cid_cal_action.action);
          break;
        }

        case CID_SETTINGS_SET:
        {
          std::vector<char> msg_temp(110, 0);
          std::memcpy(&msg_temp[0], &data_Beacon.cid_settings_msg.status_flags, 1);
          std::memcpy(&msg_temp[1], &data_Beacon.cid_settings_msg.status_output, 1);
          std::memcpy(&msg_temp[2], &data_Beacon.cid_settings_msg.uart_main_baud, 1);
          std::memcpy(&msg_temp[3], &data_Beacon.cid_settings_msg.uart_aux_baud, 1);
          std::memcpy(&msg_temp[4], &data_Beacon.cid_settings_msg.net_mac_addr.bytes, 6);
          std::memcpy(&msg_temp[10], &data_Beacon.cid_settings_msg.net_ip_addr.bytes, 4);
          std::memcpy(&msg_temp[14], &data_Beacon.cid_settings_msg.net_ip_subnet.bytes, 4);
          std::memcpy(&msg_temp[18], &data_Beacon.cid_settings_msg.net_ip_gateway.bytes, 4);
          std::memcpy(&msg_temp[22], &data_Beacon.cid_settings_msg.net_ip_dns.bytes, 4);
          std::memcpy(&msg_temp[26], &data_Beacon.cid_settings_msg.net_tcp_port, 2);
          std::memcpy(&msg_temp[28], &data_Beacon.cid_settings_msg.env_flags, 1);
          std::memcpy(&msg_temp[29], &data_Beacon.cid_settings_msg.env_pressure_ofs, 4);
          std::memcpy(&msg_temp[33], &data_Beacon.cid_settings_msg.env_salinity, 2);
          std::memcpy(&msg_temp[35], &data_Beacon.cid_settings_msg.env_vos, 2);
          std::memcpy(&msg_temp[37], &data_Beacon.cid_settings_msg.ahrs_flags, 1);
          std::memcpy(&msg_temp[38], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_x, 2);
          std::memcpy(&msg_temp[40], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_y, 2);
          std::memcpy(&msg_temp[42], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_z, 2);
          std::memcpy(&msg_temp[44], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_x, 2);
          std::memcpy(&msg_temp[46], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_y, 2);
          std::memcpy(&msg_temp[48], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_z, 2);
          std::memcpy(&msg_temp[50], &data_Beacon.cid_settings_msg.ahrs_cal.mag_valid, 1);
          std::memcpy(&msg_temp[51], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_x, 4);
          std::memcpy(&msg_temp[55], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_y, 4);
          std::memcpy(&msg_temp[59], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_z, 4);
          std::memcpy(&msg_temp[63], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_x, 4);
          std::memcpy(&msg_temp[67], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_y, 4);
          std::memcpy(&msg_temp[71], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_z, 4);
          std::memcpy(&msg_temp[75], &data_Beacon.cid_settings_msg.ahrs_cal.mag_field, 4);
          std::memcpy(&msg_temp[79], &data_Beacon.cid_settings_msg.ahrs_cal.mag_error, 4);
          std::memcpy(&msg_temp[83], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_x, 2);
          std::memcpy(&msg_temp[85], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_y, 2);
          std::memcpy(&msg_temp[87], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_z, 2);
          std::memcpy(&msg_temp[89], &data_Beacon.cid_settings_msg.ahrs_yaw_ofs, 2);
          std::memcpy(&msg_temp[91], &data_Beacon.cid_settings_msg.ahrs_pitch_ofs, 2);
          std::memcpy(&msg_temp[93], &data_Beacon.cid_settings_msg.ahrs_roll_ofs, 2);
          std::memcpy(&msg_temp[95], &data_Beacon.cid_settings_msg.xcvr_flags, 1);
          std::memcpy(&msg_temp[96], &data_Beacon.cid_settings_msg.xcvr_beacon_id, 1);
          std::memcpy(&msg_temp[97], &data_Beacon.cid_settings_msg.xcvr_range_tmo, 2);
          std::memcpy(&msg_temp[99], &data_Beacon.cid_settings_msg.xcvr_resp_time, 2);
          std::memcpy(&msg_temp[101], &data_Beacon.cid_settings_msg.xcvr_yaw, 2);
          std::memcpy(&msg_temp[103], &data_Beacon.cid_settings_msg.xcvr_pitch, 2);
          std::memcpy(&msg_temp[105], &data_Beacon.cid_settings_msg.xcvr_roll, 2);
          std::memcpy(&msg_temp[107], &data_Beacon.cid_settings_msg.xcvr_posflt_vel, 1);
          std::memcpy(&msg_temp[108], &data_Beacon.cid_settings_msg.xcvr_posflt_ang, 1);
          std::memcpy(&msg_temp[109], &data_Beacon.cid_settings_msg.xcvr_posflt_tmo, 1);
          message_build += String::toHex(msg_temp);
          break;
        }
        
        case CID_SYS_REBOOT:
          message_build += String::str("%02X%02X",0x95,0x6A);
          break;

        case CID_NAV_BEACON_POS_SEND:
        {
          std::vector<char> msg_temp(7, 0);
          std::memcpy(&msg_temp[0], &data_Beacon.cid_nav_beacon_pos_send_msg.beacon_id, 1);
          std::memcpy(&msg_temp[1], &data_Beacon.cid_nav_beacon_pos_send_msg.position_easting, 2);
          std::memcpy(&msg_temp[3],
                      &data_Beacon.cid_nav_beacon_pos_send_msg.position_northing, 2);
          std::memcpy(&msg_temp[5], &data_Beacon.cid_nav_beacon_pos_send_msg.position_depth, 2);
          message_build += String::toHex(msg_temp);
          break;
        }
        case CID_SETTINGS_SAVE:
          // not require parameters.
          break;

        case CID_SYS_INFO:
          // not require parameters.
          break;

        case CID_NAV_REF_POS_SEND:
        {
          std::vector<char> msg_temp(8, 0);
          std::memcpy(&msg_temp[0], &data_Beacon.cid_nav_ref_pos_send_msg.position_latitude, 4);
          std::memcpy(&msg_temp[4], &data_Beacon.cid_nav_ref_pos_send_msg.position_longitude, 4);
          message_build += String::toHex(msg_temp);
          break;
        }
        case CID_NAV_QUERY_SEND:
          message_build+= String::str("%02X%02X",
                                      ((uint8_t)data_Beacon.cid_nav_query_send_msg.dest_id),
                                      ((uint8_t) data_Beacon.cid_nav_query_send_msg.query_flags));
          break;

          // should never get here.
        default:
          break;
      }

      // Compute CRC.
      std::string msg = String::fromHex(message_build);
      const char* msg_raw = msg.data();
      uint16_t temp_crc = CRC16::compute((uint8_t*) msg_raw, msg.size(), 0);
      uint16_t crc = ((0x00ff & temp_crc) << 8) + ((0xff00 & temp_crc) >> 8);
      check_sum = String::str("%04X",(uint16_t) crc);
      // Add parameters to the message.
      cmd += message_build;
      cmd += check_sum;
      cmd += "\n\r";
      return cmd;
    }

    // TODO: Catch permission denied exception?
    void makeDefaultSettings(const char* filename)
    {
      // Write default settings to "EEPROM" file
      ofstream eeprom;
      eeprom.open(filename);  
      if (eeprom.is_open())
      {
        eeprom << "STATUS_FLAGS=01" << endl;
        eeprom << "STATUS_OUTPUT=3F" << endl;
        eeprom << "UART_MAIN_BAUD=0D" << endl;
        eeprom << "UART_AUX_BAUD=0D" << endl;
        eeprom << "NET_MAC_ADDR=000000000000" << endl;
        eeprom << "NET_IP_ADDR=C0A801FA" << endl;
        eeprom << "NET_IP_SUBNET=C0A801FA" << endl;
        eeprom << "NET_IP_GATEWAY=C0A801FA" << endl;
        eeprom << "NET_IP_DNS=C0A801FA" << endl;
        eeprom << "NET_TCP_PORT=8100" << endl;
        eeprom << "ENV_FLAGS=03" << endl;
        eeprom << "ENV_PRESSURE_OFS=00000000" << endl;
        eeprom << "ENV_SALINITY=015E" << endl;    // 350 deci-ppt
        eeprom << "ENV_VOS=0064" << endl;
        eeprom << "AHRS_FLAGS=00" << endl;
        eeprom << "ACC_MIN_X=0000" << endl;
        eeprom << "ACC_MIN_Y=0000" << endl;
        eeprom << "ACC_MIN_Z=0000" << endl;
        eeprom << "ACC_MAX_X=0000" << endl;
        eeprom << "ACC_MAX_Y=0000" << endl;
        eeprom << "ACC_MAX_Z=0000" << endl;
        eeprom << "MAG_VALID=00" << endl;
        eeprom << "MAG_HARD_X=00000000" << endl;
        eeprom << "MAG_HARD_Y=00000000" << endl;
        eeprom << "MAG_HARD_Z=00000000" << endl;
        eeprom << "MAG_SOFT_X=00000000" << endl;
        eeprom << "MAG_SOFT_Y=00000000" << endl;
        eeprom << "MAG_SOFT_Z=00000000" << endl;
        eeprom << "MAG_FIELD=00000000" << endl;
        eeprom << "MAG_ERROR=00000000" << endl;
        eeprom << "GYRO_OFS_X=0000" << endl;
        eeprom << "GYRO_OFS_Y=0000" << endl;
        eeprom << "GYRO_OFS_Z=0000" << endl;
        eeprom << "AHRS_YAW_OFS=0000" << endl;
        eeprom << "AHRS_PITCH_OFS=0000" << endl;
        eeprom << "AHRS_ROLL_OFS=0000" << endl;
        eeprom << "XCVR_FLAGS=00" << endl;
        eeprom << "XCVR_BEACON_ID=01" << endl;
        eeprom << "XCVR_RANGE_TMO=0064" << endl;
        eeprom << "XCVR_RESP_TIME=000A" << endl;
        eeprom << "XCVR_YAW=0000" << endl;
        eeprom << "XCVR_PITCH=0000" << endl;
        eeprom << "XCVR_ROLL=0000" << endl;
        eeprom << "XCVR_POSFLT_VEL=00" << endl;
        eeprom << "XCVR_POSFLT_ANG=00" << endl;
        eeprom << "XCVR_POSFLT_TMO=00" << endl;
      }

      eeprom.close();
    }

    void getSettingsEEPROM(const char* filename, DataSeatrac& data_Beacon)
    {
      // Check if EEPROM file exists, if not create one from default configurations
      // (according to developer manual)
      struct stat buffer;
      if(!(stat (filename, &buffer) == 0))
        makeDefaultSettings(filename);

      ifstream eeprom;
      eeprom.open(filename);
      
      if (eeprom.is_open())
      {
        string line, data, datahex;

        // Read until end of file
        while(getline(eeprom, line))
        {
          size_t token_pos = line.find("=");
          string token = line.substr(0, token_pos);
          string value = line.substr(token_pos+1, line.size());
          data += value;
        }

        // Exploit parseCommand function to populate DataSeatrac structure
        datahex = String::fromHex(data);
        const char* raw_msg = datahex.data();        
        // Pretend we received a "settings get" response (i.e., another beacon has sent us they settings)
        parseResponse(CID_SETTINGS_GET, raw_msg, data_Beacon);
      }
    }

    void saveSettingsEEPROM(const char* filename, DataSeatrac& data_Beacon)
    {
      // Get all current settings as in CID_SETTINGS_SET command parsing
      std::vector<char> msg_temp(110, 0);
      std::memcpy(&msg_temp[0], &data_Beacon.cid_settings_msg.status_flags, 1);
      std::memcpy(&msg_temp[1], &data_Beacon.cid_settings_msg.status_output, 1);
      std::memcpy(&msg_temp[2], &data_Beacon.cid_settings_msg.uart_main_baud, 1);
      std::memcpy(&msg_temp[3], &data_Beacon.cid_settings_msg.uart_aux_baud, 1);
      std::memcpy(&msg_temp[4], &data_Beacon.cid_settings_msg.net_mac_addr.bytes, 6);
      std::memcpy(&msg_temp[10], &data_Beacon.cid_settings_msg.net_ip_addr.bytes, 4);
      std::memcpy(&msg_temp[14], &data_Beacon.cid_settings_msg.net_ip_subnet.bytes, 4);
      std::memcpy(&msg_temp[18], &data_Beacon.cid_settings_msg.net_ip_gateway.bytes, 4);
      std::memcpy(&msg_temp[22], &data_Beacon.cid_settings_msg.net_ip_dns.bytes, 4);
      std::memcpy(&msg_temp[26], &data_Beacon.cid_settings_msg.net_tcp_port, 2);
      std::memcpy(&msg_temp[28], &data_Beacon.cid_settings_msg.env_flags, 1);
      std::memcpy(&msg_temp[29], &data_Beacon.cid_settings_msg.env_pressure_ofs, 4);
      std::memcpy(&msg_temp[33], &data_Beacon.cid_settings_msg.env_salinity, 2);
      std::memcpy(&msg_temp[35], &data_Beacon.cid_settings_msg.env_vos, 2);
      std::memcpy(&msg_temp[37], &data_Beacon.cid_settings_msg.ahrs_flags, 1);
      std::memcpy(&msg_temp[38], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_x, 2);
      std::memcpy(&msg_temp[40], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_y, 2);
      std::memcpy(&msg_temp[42], &data_Beacon.cid_settings_msg.ahrs_cal.acc_min_z, 2);
      std::memcpy(&msg_temp[44], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_x, 2);
      std::memcpy(&msg_temp[46], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_y, 2);
      std::memcpy(&msg_temp[48], &data_Beacon.cid_settings_msg.ahrs_cal.acc_max_z, 2);
      std::memcpy(&msg_temp[50], &data_Beacon.cid_settings_msg.ahrs_cal.mag_valid, 1);
      std::memcpy(&msg_temp[51], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_x, 4);
      std::memcpy(&msg_temp[55], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_y, 4);
      std::memcpy(&msg_temp[59], &data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_z, 4);
      std::memcpy(&msg_temp[63], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_x, 4);
      std::memcpy(&msg_temp[67], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_y, 4);
      std::memcpy(&msg_temp[71], &data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_z, 4);
      std::memcpy(&msg_temp[75], &data_Beacon.cid_settings_msg.ahrs_cal.mag_field, 4);
      std::memcpy(&msg_temp[79], &data_Beacon.cid_settings_msg.ahrs_cal.mag_error, 4);
      std::memcpy(&msg_temp[83], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_x, 2);
      std::memcpy(&msg_temp[85], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_y, 2);
      std::memcpy(&msg_temp[87], &data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_z, 2);
      std::memcpy(&msg_temp[89], &data_Beacon.cid_settings_msg.ahrs_yaw_ofs, 2);
      std::memcpy(&msg_temp[91], &data_Beacon.cid_settings_msg.ahrs_pitch_ofs, 2);
      std::memcpy(&msg_temp[93], &data_Beacon.cid_settings_msg.ahrs_roll_ofs, 2);
      std::memcpy(&msg_temp[95], &data_Beacon.cid_settings_msg.xcvr_flags, 1);
      std::memcpy(&msg_temp[96], &data_Beacon.cid_settings_msg.xcvr_beacon_id, 1);
      std::memcpy(&msg_temp[97], &data_Beacon.cid_settings_msg.xcvr_range_tmo, 2);
      std::memcpy(&msg_temp[99], &data_Beacon.cid_settings_msg.xcvr_resp_time, 2);
      std::memcpy(&msg_temp[101], &data_Beacon.cid_settings_msg.xcvr_yaw, 2);
      std::memcpy(&msg_temp[103], &data_Beacon.cid_settings_msg.xcvr_pitch, 2);
      std::memcpy(&msg_temp[105], &data_Beacon.cid_settings_msg.xcvr_roll, 2);
      std::memcpy(&msg_temp[107], &data_Beacon.cid_settings_msg.xcvr_posflt_vel, 1);
      std::memcpy(&msg_temp[108], &data_Beacon.cid_settings_msg.xcvr_posflt_ang, 1);
      std::memcpy(&msg_temp[109], &data_Beacon.cid_settings_msg.xcvr_posflt_tmo, 1);
      string settings = String::toHex(msg_temp);
      
      // Write settings to "EEPROM" file
      ofstream eeprom;
      eeprom.open(filename);  
      if (eeprom.is_open())
      {
        int ind = 0;
        eeprom << "STATUS_FLAGS=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "STATUS_OUTPUT=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "UART_MAIN_BAUD=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "UART_AUX_BAUD=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "NET_MAC_ADDR=" << settings.substr(ind, 12) << endl; ind += 12;
        eeprom << "NET_IP_ADDR=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "NET_IP_SUBNET=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "NET_IP_GATEWAY=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "NET_IP_DNS=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "NET_TCP_PORT=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "ENV_FLAGS=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "ENV_PRESSURE_OFS=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "ENV_SALINITY=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "ENV_VOS=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "AHRS_FLAGS=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "ACC_MIN_X=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "ACC_MIN_Y=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "ACC_MIN_Z=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "ACC_MAX_X=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "ACC_MAX_Y=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "ACC_MAX_Z=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "MAG_VALID=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "MAG_HARD_X=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "MAG_HARD_Y=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "MAG_HARD_Z=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "MAG_SOFT_X=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "MAG_SOFT_Y=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "MAG_SOFT_Z=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "MAG_FIELD=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "MAG_ERROR=" << settings.substr(ind, 8) << endl; ind += 8;
        eeprom << "GYRO_OFS_X=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "GYRO_OFS_Y=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "GYRO_OFS_Z=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "AHRS_YAW_OFS=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "AHRS_PITCH_OFS=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "AHRS_ROLL_OFS=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "XCVR_FLAGS=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "XCVR_BEACON_ID=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "XCVR_RANGE_TMO=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "XCVR_RESP_TIME=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "XCVR_YAW=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "XCVR_PITCH=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "XCVR_ROLL=" << settings.substr(ind, 4) << endl; ind += 4;
        eeprom << "XCVR_POSFLT_VEL=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "XCVR_POSFLT_ANG=" << settings.substr(ind, 2) << endl; ind += 2;
        eeprom << "XCVR_POSFLT_TMO=" << settings.substr(ind, 2) << endl; ind += 2;
      }

      eeprom.close();
    }
  }  
}

#endif

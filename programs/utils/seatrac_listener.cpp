// C headers (for socket, signal...)
#include <arpa/inet.h> 
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

// C++ headers
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include <DUNE/DUNE.hpp>

// Seatrac message parser for DataSeatrac struct
#include <Transports/Seatrac/Parser.hpp>

using namespace std;
string m_data;

// Socket definitions
int sock_fd; 
struct sockaddr_in servaddr; 
int addrlen = sizeof(servaddr);

// Print acofix data
void printAcoFix(Transports::Seatrac::Acofix_t& aco_fix)
{
    cout << "-Acofix data-" << endl; 
    cout << "Destination ID: " << aco_fix.dest_id << endl;
    cout << "Source ID: " << aco_fix.src_id << endl;
    
    cout << "Message flags: " << endl;
    if (aco_fix.flags & (1 << 1))
        cout << "USBL_VALID" << endl;
    if (aco_fix.flags & (1 << 2))
        cout << "POSITION_VALID" << endl;
    if (aco_fix.flags & (1 << 3))
        cout << "POSITION_ENHANCED" << endl;
    if (aco_fix.flags & (1 << 4))
        cout << "POSITION_FLT_ERROR" << endl;

    cout << "Message type: ";
    switch (aco_fix.amsgtype_e){
        case Transports::Seatrac::MSG_OWAY:
            cout << "MSG_OWAY (One-way)" << endl;
            break;
        case Transports::Seatrac::MSG_OWAYU:
            cout << "MSG_OWAYU (One-way USBL)" << endl;
            break;
        case Transports::Seatrac::MSG_REQ:
            cout << "MSG_REQ (Request, must receive response)" << endl;
            break;
        case Transports::Seatrac::MSG_RESP:
            cout << "MSG_RESP (Response to previous request)" << endl;
            break;
        case Transports::Seatrac::MSG_REQU:
            cout << "MSG_REQU (Request with USBL info)" << endl;
            break;
        case Transports::Seatrac::MSG_RESPU:
            cout << "MSG_RESPU (Response with USBL info)" << endl;
            break;
        case Transports::Seatrac::MSG_REQX:
            cout << "MSG_REQX (Request with extended Depth and USBL info)" << endl;
            break;
        case Transports::Seatrac::MSG_RESPX:
            cout << "MSG_RESPX (Response with extended Depth and USBL info)" << endl;
            break;
        default:
            cout << "Unknown message" << endl;
            break;
    }

    cout << "Local beacon attitude roll (X): " << aco_fix.attitude_roll / 10.0 << " degrees" << endl;
    cout << "Local beacon attitude pitch (Y): " << aco_fix.attitude_pitch / 10.0 << " degrees" << endl;
    cout << "Local beacon attitude yaw (Z): " << aco_fix.attitude_yaw / 10.0 << " degrees" << endl;
    cout << "Local beacon depth: " << aco_fix.depth_local / 10.0 << " meters" << endl;
    cout << "Local beacon velocity-of-sound: " << aco_fix.vos / 10.0 << " meters-per-second" << endl;
    cout << "Local beacon Received Signal Strength" << aco_fix.rssi / 10.0 << " decibels" << endl;

    // Range fields.
    if (aco_fix.outputflags_list[0])
    {
        cout << "Range count: " << aco_fix.range_count << endl;
        cout << "Range time: " << aco_fix.range_time / 10000000 << " seconds" << endl;
        cout << "Range distance (LoS): " << aco_fix.range_dist / 10.0 << " meters" << endl;
    }

    // USBL Fields.
    if (aco_fix.outputflags_list[1])
    {
        cout << "Number of USBL channels: " << aco_fix.usbl_channels << endl;
        cout << "USBL channel RSSI values: [";
        for (int i = 0; i < aco_fix.usbl_channels; i++)
            cout << aco_fix.usbl_rssi[i] << " ";
        cout << "]" << endl;

        cout << "USBL azimuth angle: " << aco_fix.usbl_azimuth / 10.0 << " degrees" << endl;
        cout << "USBL elevation angle: " << aco_fix.usbl_elevation / 10.0 << " degrees" << endl;
        cout << "USBL fit errror: " << aco_fix.usbl_fit_error / 100.0 << endl;
    }

    // Position Fields.
    if (aco_fix.outputflags_list[2])
    {
        cout << "USBL position easting: " << aco_fix.position_easting / 10.0 << " meters" << endl;
        cout << "USBL position northing: " << aco_fix.position_northing / 10.0 << " meters" << endl;
        cout << "USBL position depth: " << aco_fix.position_depth / 10.0 << " meters" << endl;
    }
}

// Print the parsed message data
void
dataPrint(uint16_t message_type, Transports::Seatrac::DataSeatrac& data_Beacon)
{
    switch (message_type) {
        case Transports::Seatrac::CID_STATUS:
            cout << "--System operation status--" << endl;
            cout << "Status output flags: " << DUNE::Utils::String::str("0x%02X",(uint8_t) data_Beacon.cid_status_msg.output_flags) << endl;
            // cout << "Output flags: " << endl;
            // cout << "ENVIRONMENT_FLAG: " 
            //      << data_Beacon.cid_status_msg.outputflags_list[0]) << endl;
            // cout << "ATTITUDE_FLAG: " 
            //      << data_Beacon.cid_status_msg.outputflags_list[1]) << endl;
            // cout << "MAG_CAL_FLAG: " 
            //      << data_Beacon.cid_status_msg.outputflags_list[2]) << endl;
            // cout << "ACC_CAL_FLAG: " 
            //      << data_Beacon.cid_status_msg.outputflags_list[3]) << endl;
            // cout << "AHRS_RAW_DATA_FLAG: " 
            //      << data_Beacon.cid_status_msg.outputflags_list[4]) << endl;
            // cout << "AHRS_COMP_DATA_FLAG: " 
            //      << data_Beacon.cid_status_msg.outputflags_list[5]) << endl;
            
            // Environment.
            if (data_Beacon.cid_status_msg.outputflags_list[0])
            {
                cout << "-Environmental info-" << endl;
                cout << "Beacon supply voltage: " 
                    << data_Beacon.cid_status_msg.environment_supply / 1000.0 << " Volts" << endl;
                cout << "Water temperature: "
                    << data_Beacon.cid_status_msg.environment_temperature / 10.0 << " deg. Celsius" << endl;
                cout << "Water pressure: "
                    << data_Beacon.cid_status_msg.environment_pressure / 1000.0 << " Bar" << endl;
                cout << "Beacon depth: "
                    << data_Beacon.cid_status_msg.EnvironmentDepth / 10.0 << " meters" << endl;
                cout << "Velocity-of-sound: "
                    << data_Beacon.cid_status_msg.EnvironmentVos / 10.0 << " meters-per-second" << endl;
            }

            // Attitude.
            if (data_Beacon.cid_status_msg.outputflags_list[1])
            {
                cout << "-Attitude info-" << endl;
                cout << "Roll (X): " << data_Beacon.cid_status_msg.attitude_roll / 10.0  << " degrees" << endl;
                cout << "Pitch (Y): " << data_Beacon.cid_status_msg.attitude_pitch / 10.0 << " degrees" << endl;
                cout << "Yaw (Z): " << data_Beacon.cid_status_msg.attitude_yaw / 10.0 << " degrees" << endl;
            }

            // Mag cal.
            if (data_Beacon.cid_status_msg.outputflags_list[2])
            {
                cout << "-Magnetometer calibration status-" << endl;
                cout << "Mag. calibration progress: " << DUNE::Utils::String::str("%d", data_Beacon.cid_status_msg.mag_cal_buf) << " %" << endl;
                cout << "Mag. calibration validity: " << DUNE::Utils::String::str("%d", data_Beacon.cid_status_msg.mag_cal_valid) << endl;
                cout << "Mag. calibration age: " << data_Beacon.cid_status_msg.mag_cal_age << " seconds" << endl;
                cout << "Mag. calibration fit: " << DUNE::Utils::String::str("%d", data_Beacon.cid_status_msg.mag_cal_fit) << " %" << endl;
            }

            // Acc cal.
            if (data_Beacon.cid_status_msg.outputflags_list[3])
            {
                // Will have to look at these values on the hardware to see if they're m/s or G
                cout << "-Accelerometer calibration status-" << endl;
                cout << "Minimum X acc: " << data_Beacon.cid_status_msg.acc_lim_min_x << endl;
                cout << "Minimum Y acc: " << data_Beacon.cid_status_msg.acc_lim_min_y << endl;
                cout << "Minimum Z acc: " << data_Beacon.cid_status_msg.acc_lim_min_z << endl;
                cout << "Maximum X acc: " << data_Beacon.cid_status_msg.acc_lim_max_x << endl;
                cout << "Maximum Y acc: " << data_Beacon.cid_status_msg.acc_lim_max_y << endl;
                cout << "Maximum Z acc: " << data_Beacon.cid_status_msg.acc_lim_max_z << endl;
            }

            // AHRS raw data.
            if (data_Beacon.cid_status_msg.outputflags_list[4])
            {
                // Will have to look at these values on the hardware to see if they're m/s or G
                cout << "-AHRS raw data-" << endl;
                cout << "Acc. X: " << data_Beacon.cid_status_msg.ahrs_raw_acc_x << endl;
                cout << "Acc. Y: " << data_Beacon.cid_status_msg.ahrs_raw_acc_y << endl;
                cout << "Acc. Z: " << data_Beacon.cid_status_msg.ahrs_raw_acc_z << endl;
                cout << "Mag. X: " << data_Beacon.cid_status_msg.ahrs_raw_mag_x << endl;
                cout << "Mag. Y: " << data_Beacon.cid_status_msg.ahrs_raw_mag_y << endl;
                cout << "Mag. Z: " << data_Beacon.cid_status_msg.ahrs_raw_mag_z << endl;
                cout << "Gyro X: " << data_Beacon.cid_status_msg.ahrs_raw_gyro_x << endl;
                cout << "Gyro Y: " << data_Beacon.cid_status_msg.ahrs_raw_gyro_y << endl;
                cout << "Gyro Z: " << data_Beacon.cid_status_msg.ahrs_raw_gyro_z << endl;
            }

            // AHRS compensated data.
            if (data_Beacon.cid_status_msg.outputflags_list[5])
            {
                // Will have to look at these values on the hardware to see if they're m/s or G
                cout << "-AHRS compensated data-" << endl;
                cout << "Acc. X: " << data_Beacon.cid_status_msg.ahrs_comp_acc_x << endl;
                cout << "Acc. Y: " << data_Beacon.cid_status_msg.ahrs_comp_acc_y << endl;
                cout << "Acc. Z: " << data_Beacon.cid_status_msg.ahrs_comp_acc_z << endl;
                cout << "Mag. X: " << data_Beacon.cid_status_msg.ahrs_comp_mag_x << endl;
                cout << "Mag. Y: " << data_Beacon.cid_status_msg.ahrs_comp_mag_y << endl;
                cout << "Mag. Z: " << data_Beacon.cid_status_msg.ahrs_comp_mag_z << endl;
                cout << "Gyro X: " << data_Beacon.cid_status_msg.ahrs_comp_gyro_x << endl;
                cout << "Gyro Y: " << data_Beacon.cid_status_msg.ahrs_comp_gyro_y << endl;
                cout << "Gyro Z: " << data_Beacon.cid_status_msg.ahrs_comp_gyro_z << endl;
            }
            break;

        // Ping REQUEST to remote beacon from local beacon, must be tested in the water
        case Transports::Seatrac::CID_PING_REQ:
            cout << "--Ping request--" << endl;
            printAcoFix(data_Beacon.cid_ping_req_msg.aco_fix);
            break;

        // Ping RESPONSE from remote beacon to local beacon, must be tested in the water
        case Transports::Seatrac::CID_PING_RESP:
            cout << "--Ping response--" << endl;
            printAcoFix(data_Beacon.cid_ping_resp_msg.aco_fix);
            break;

        case Transports::Seatrac::CID_PING_ERROR:
            cout << "--Ping error--" << endl;
            cout << "Beacon ID: " << data_Beacon.cid_ping_error_msg.beacon_id << endl;
            cout << "Error: ";
            switch (data_Beacon.cid_ping_error_msg.status){
                case Transports::Seatrac::CST_XCVR_RESP_TIMEOUT:
                    cout << "Timeout (A valid response message was not received in the "
                        << "time allowed by the beacons Range-Timeout setting)";
                    break;
                case Transports::Seatrac::CST_XCVR_RESP_WRONG:
                    cout << "Collision (A message from another beacon was received while "
                        << "waiting for a response)";
                    break;
                case Transports::Seatrac::CST_XCVR_RESP_ERROR:
                    cout << "Reception (A general reception error has occurred while waiting "
                        << "for a response)";
                    break;
                default:
                    break;
            }
            cout << endl;
            break;

        case Transports::Seatrac::CID_PING_SEND:
            cout << "--Ping send--" << endl;
            cout << "Beacon ID: " << data_Beacon.cid_ping_send_msg.beacon_id << endl;
            cout << "Status: ";
            switch (data_Beacon.cid_ping_send_msg.status){
                case Transports::Seatrac::CST_OK:
                    cout << "OK (The PING command is being sent)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_INVALID:
                    cout << "Invalid parameters (The DEST_ID parameter is invalid)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_MISSING:
                    cout << "Missing parameters (The DEST_ID has not been specified correctly)";
                    break;
                case Transports::Seatrac::CST_XCVR_BUSY:
                    cout << "Busy (The message cannot be sent as the acoustic transceiver is busy "
                        << "performing another operation)";
                    break;
                default:
                    break;
            }
            cout << endl;
            break;

        case Transports::Seatrac::CID_DAT_SEND:
            cout << "--DAT (datagram) send--" << endl;
            cout << "Beacon ID: " << data_Beacon.cid_dat_send_msg.beacon_id << endl;
            cout << "Status: ";
            switch (data_Beacon.cid_dat_send_msg.status){
                case Transports::Seatrac::CST_OK:
                    cout << "OK (The DAT command is being sent)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_INVALID:
                    cout << "Invalid parameters (The value of one of the parameters is invalid)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_MISSING:
                    cout << "Missing parameters (There is not enough data parameters provided to "
                         << "satisfy the message requirements)";
                    break;
                case Transports::Seatrac::CST_XCVR_BUSY:
                    cout << "Busy (The message cannot be sent as the acoustic transceiver is busy "
                         << "performing another operation)";
                    break;
                default:
                    break;
            }
            cout << endl;
            break;

        case Transports::Seatrac::CID_DAT_RECEIVE:
            cout << "--DAT (datagram) receive--" << endl;
            printAcoFix(data_Beacon.cid_dat_receive_msg.aco_fix);
            if (data_Beacon.cid_dat_receive_msg.ack_flag){
                cout << "ACK_FLAG: True (message has been generated as a response to a "
                     << "CID_DAT_SEND command which requested an ACK)" << endl;
            } else
                cout << "ACK_FLAG: False" << endl;
            cout << "Packet length: " << data_Beacon.cid_dat_receive_msg.packet_len << endl;
            cout << "Packet data: [" << endl;
            for (int i = 0; i < data_Beacon.cid_dat_receive_msg.packet_len; i++) {
                cout << data_Beacon.cid_dat_receive_msg.packet_data[i] << " ";
            }
            cout << "]" << endl;
            break;

        case Transports::Seatrac::CID_DAT_ERROR:
            cout << "--Ping error--" << endl;
            cout << "Beacon ID: " << data_Beacon.cid_dat_send_msg.beacon_id << endl;
            cout << "Error: ";
            switch (data_Beacon.cid_dat_send_msg.status){
                case Transports::Seatrac::CST_XCVR_RESP_TIMEOUT:
                    cout << "Timeout (A valid response message was not received in the "
                        << "time allowed by the beacons Range-Timeout setting)";
                    break;
                case Transports::Seatrac::CST_XCVR_RESP_WRONG:
                    cout << "Collision (A message from another beacon was received while "
                        << "waiting for a response)";
                    break;
                case Transports::Seatrac::CST_XCVR_RESP_ERROR:
                    cout << "Reception (A general reception error has occurred while waiting "
                        << "for a response)";
                    break;
                default:
                    break;
            }
            cout << endl;
            break;

        case Transports::Seatrac::CID_SETTINGS_GET:
            cout << "--Beacon settings--" << endl;
            cout << "Status generation flags: " << DUNE::Utils::String::str("0x%02X",(uint8_t) data_Beacon.cid_settings_msg.status_flags) << endl;
            cout << "Status output flags: " << DUNE::Utils::String::str("0x%02X",(uint8_t) data_Beacon.cid_settings_msg.status_output) << endl;
            cout << "Main comm port UART baud rate: " << data_Beacon.cid_settings_msg.uart_main_baud << endl;
            cout << "Aux. comm port UART baud rate: " << data_Beacon.cid_settings_msg.uart_aux_baud << endl;
            cout << "Net mac address (reserved): " << data_Beacon.cid_settings_msg.net_mac_addr.bytes << endl;
            cout << "Net IP address (reserved): " << data_Beacon.cid_settings_msg.net_ip_addr.bytes << endl;
            cout << "Net subnet address (reserved): " << data_Beacon.cid_settings_msg.net_ip_subnet.bytes << endl;
            cout << "Net gateway address (reserved): " << data_Beacon.cid_settings_msg.net_ip_gateway.bytes << endl;
            cout << "Net DNS address (reserved): " << data_Beacon.cid_settings_msg.net_ip_dns.bytes << endl;
            cout << "Net TCP port (reserved): " << data_Beacon.cid_settings_msg.net_tcp_port << endl;
            cout << "Environment sensor flags: " << DUNE::Utils::String::str("0x%02X",(uint8_t) data_Beacon.cid_settings_msg.env_flags) << endl;
            cout << "Environment pressure offset: " << data_Beacon.cid_settings_msg.env_pressure_ofs / 1000.0 
                 << " Bar" << endl;
            cout << "Environemnt salinity: " << data_Beacon.cid_settings_msg.env_salinity / 10.0 
                 << " parts-per-thousand" << endl;
            cout << "Environment Velocity-of-sound: " << data_Beacon.cid_settings_msg.env_vos / 10.0 
                 << " meters-per-second" << endl;
            cout << "AHRS flags: " << DUNE::Utils::String::str("0x%02X",(uint8_t) data_Beacon.cid_settings_msg.ahrs_flags) << endl;
            cout << "Accelerometer calibration min. X: " << data_Beacon.cid_settings_msg.ahrs_cal.acc_min_x << endl;
            cout << "Accelerometer calibration min. Y: " << data_Beacon.cid_settings_msg.ahrs_cal.acc_min_y << endl;
            cout << "Accelerometer calibration min. Z: " << data_Beacon.cid_settings_msg.ahrs_cal.acc_min_z << endl;
            cout << "Accelerometer calibration max. X: " << data_Beacon.cid_settings_msg.ahrs_cal.acc_max_x << endl;
            cout << "Accelerometer calibration max. Y: " << data_Beacon.cid_settings_msg.ahrs_cal.acc_max_y << endl;
            cout << "Accelerometer calibration max. Z: " << data_Beacon.cid_settings_msg.ahrs_cal.acc_max_z << endl;
            cout << "Mag. calibration validity: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_valid << endl;
            cout << "Mag. hard iron X offset: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_x << endl;
            cout << "Mag. hard iron Y offset: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_y << endl;
            cout << "Mag. hard iron Z offset: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_hard_z << endl;
            cout << "Mag. soft iron X offset: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_x << endl;
            cout << "Mag. soft iron X offset: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_y << endl;
            cout << "Mag. soft iron X offset: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_soft_z << endl;
            cout << "Mag. calibration magnetic field: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_field << endl;
            cout << "Mag. calibration fit error: " << data_Beacon.cid_settings_msg.ahrs_cal.mag_error << endl;
            cout << "Gyro X offset: " << data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_x << endl;
            cout << "Gyro Y offset: " << data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_y << endl;
            cout << "Gyro Z offset: " << data_Beacon.cid_settings_msg.ahrs_cal.gyro_offset_z << endl;
            cout << "AHRS roll offset: " << data_Beacon.cid_settings_msg.ahrs_roll_ofs / 10.0 << " degrees" << endl;
            cout << "AHRS pitch offset: " << data_Beacon.cid_settings_msg.ahrs_pitch_ofs / 10.0 << " degrees" << endl;
            cout << "AHRS yaw offset: " << data_Beacon.cid_settings_msg.ahrs_yaw_ofs / 10.0 << " degrees" << endl;
            cout << "Control operation flags: " << DUNE::Utils::String::str("0x%02X",(uint8_t) data_Beacon.cid_settings_msg.xcvr_flags) << endl;
            cout << "Beacon ID: " << data_Beacon.cid_settings_msg.xcvr_beacon_id << endl;
            cout << "Range distance timeout: " << data_Beacon.cid_settings_msg.xcvr_range_tmo << " meters" << endl;
            cout << "Response turnaround time: " << data_Beacon.cid_settings_msg.xcvr_resp_time << " milliseconds" << endl;
            cout << "Range distance timeout: " << data_Beacon.cid_settings_msg.xcvr_range_tmo << " meters" << endl;
            cout << "Manually-defined AHRS roll: " << data_Beacon.cid_settings_msg.xcvr_roll / 10.0 << " degrees" << endl;
            cout << "Manually-defined AHRS pitch: " << data_Beacon.cid_settings_msg.xcvr_pitch / 10.0 << " degrees" << endl;
            cout << "Manually-defined AHRS yaw: " << data_Beacon.cid_settings_msg.xcvr_yaw / 10.0 << " degrees" << endl;
            cout << "Position filter velocity limit: " << data_Beacon.cid_settings_msg.xcvr_posflt_vel <<  " meters-per-second" << endl;
            cout << "Position filter angular limit: " << data_Beacon.cid_settings_msg.xcvr_posflt_ang <<  " degrees" << endl;
            cout << "Position filter timeout limit: " << data_Beacon.cid_settings_msg.xcvr_posflt_tmo <<  " seconds" << endl;
            break;

        case  Transports::Seatrac::CID_NAV_QUERY_REQ:
            cout << "--Accoustic nav message request--" << endl;
            printAcoFix(data_Beacon.cid_nav_query_req_msg.aco_fix);
            break;

        case  Transports::Seatrac::CID_XCVR_FIX:
            cout << "--Accoustic nav message request--" << endl;
            printAcoFix(data_Beacon.cid_xcvr_fix_msg.aco_fix);
            break;

        // TODO
        // case CID_NAV_QUERY_RESP:
        //     data_Beacon.set(CID_NAV_QUERY_RESP);
        //     ind = updateEcoFix(&data_Beacon.cid_nav_querry_resp_msg.aco_fix, ind, msg_raw);
        //     std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.query_flags, msg_raw + ind, 1);
        //     ind += 1;
        //     data_Beacon.cid_nav_querry_resp_msg.queryFlagsExtract();

        //     if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[0])
        //     {
        //     std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_depth, msg_raw + ind,4);
        //     ind += 4;
        //     }

        //     if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[1])
        //     {
        //     std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_supply, msg_raw + ind, 2);
        //     ind += 2;
        //     }

        //     if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[2])
        //     {
        //     std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_temp, msg_raw + ind, 2);
        //     ind += 2;
        //     }

        //     if (data_Beacon.cid_nav_querry_resp_msg.query_flags_list[3])
        //     {
        //     std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_yaw, msg_raw + ind, 2);
        //     std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_pitch,
        //                 msg_raw + ind + 2, 2);
        //     std::memcpy(&data_Beacon.cid_nav_querry_resp_msg.remote_roll,
        //                 msg_raw + ind + 4, 2);
        //     }
        //     break;

        case  Transports::Seatrac::CID_SYS_REBOOT:
            cout << "--System software reset--" << endl;
            cout << "Status: ";
            switch (data_Beacon.cid_sys_reboot_msg.status){
                case Transports::Seatrac::CST_OK:
                    cout << "OK (The command was performed successfully)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_MISSING:
                    cout << "Parameter missing (CHECK parameter not specified in command message)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_INVALID:
                    cout << "Parameter invalid (CHECK parameter incorrect in command message)";
                    break;
                default:
                    break;
            }
            cout << endl;
            break;

        case Transports::Seatrac::CID_SETTINGS_SET:
            cout << "--Settings SET--" << endl;
            cout << "Status: ";
            switch (data_Beacon.cid_sys_settings_set_msg.status){
                case Transports::Seatrac::CST_OK:
                    cout << "OK (The command was performed successfully)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_MISSING:
                    cout << "Missing parameter (The settings parameter were not specified correctly)";
                    break;
                default: break;
            }
            cout << endl;
            break;

        case Transports::Seatrac::CID_CAL_ACTION:
            cout << "--Calibration action--" << endl;
            cout << "Status: ";
            switch (data_Beacon.cid_cal_action_msg.status){
                case Transports::Seatrac::CST_OK:
                    cout << "OK (The command was performed successfully)";
                    break;
                case Transports::Seatrac::CST_CMD_PARAM_MISSING:
                    cout << "Missing parameter (The ACTION parameter was not specified correctly)";
                    break;
                default: 
                    string resp = DUNE::Utils::String::str("%02X",(uint16_t) data_Beacon.cid_cal_action_msg.status);
                    cout << "Unknown response: " << resp << endl;
                    break;
            }
            cout << endl;
            break;

        case  Transports::Seatrac::CID_SETTINGS_SAVE:
            cout << "--Settings save--" << endl;
            cout << "Status: ";
            switch (data_Beacon.cid_settings_save_msg.status){
                case Transports::Seatrac::CST_OK:
                    cout << "OK (The command was performed successfully)";
                    break;
                case Transports::Seatrac::CST_FAIL:
                    cout << "FAIL (The settings could not be saved)";
                    break;
                default: break;
            }
            cout << endl;
            break;

        // TODO
        // case CID_NAV_QUERY_SEND:
        //     std::memcpy(&data_Beacon.cid_nav_query_send_msg.status, msg_raw, 1);
        //     break;

        // TODO
        // case CID_NAV_BEACON_POS_UPDATE:
        //     data_Beacon.set(CID_NAV_BEACON_POS_UPDATE);
        //     ind = updateEcoFix(&data_Beacon.cid_nav_beacon_pos_update_msg.aco_fix, ind, msg_raw);
        //     std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.beacon_id, msg_raw + ind, 1);
        //     std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_easting,
        //                 msg_raw + ind + 1, 2);
        //     std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_northing,
        //                 msg_raw + ind + 3, 2);
        //     std::memcpy(&data_Beacon.cid_nav_beacon_pos_update_msg.position_depth,
        //                 msg_raw + ind + 5, 2);
        //     break;

        // TODO
        // case CID_NAV_BEACON_POS_SEND:
        //     std::memcpy(&data_Beacon.cid_nav_beacon_pos_send_msg.status, msg_raw, 1);
        //     break;

        // TODO
        // case CID_NAV_REF_POS_SEND:
        //     std::memcpy(&data_Beacon.cid_nav_ref_pos_send_msg.status, msg_raw,1);
        //     break;

        // TODO
        // case CID_NAV_REF_POS_UPDATE:
        //     data_Beacon.set(CID_NAV_REF_POS_UPDATE);
        //     ind = updateEcoFix(&data_Beacon.cid_nav_ref_pos_update_msg.aco_fix, ind, msg_raw);
        //     std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.beacon_id, msg_raw + ind, 1);
        //     std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.position_latitude,
        //                 msg_raw + ind + 1, 4);
        //     std::memcpy(&data_Beacon.cid_nav_ref_pos_update_msg.position_longitude,
        //                 msg_raw + ind + 5, 4);
        //     break;

        case Transports::Seatrac::CID_SYS_INFO:
            cout << "--System information--" << endl;
            cout << "Uptime: " << data_Beacon.cid_sys_info.seconds << " seconds" << endl;
            cout << "Firmware memory section: ";
            switch (data_Beacon.cid_sys_info.section){
                case 0: cout << "Bootloader application";
                        break;
                case 1: cout << "Main application";
                        break;
                default: break;
            } 
            cout << endl;
            cout << "Hardware part number: " << data_Beacon.cid_sys_info.hardware.part_number << endl;
            cout << "Hardware part revision: " << data_Beacon.cid_sys_info.hardware.part_rev << endl;
            cout << "Hardware serial number: " << data_Beacon.cid_sys_info.hardware.serial_number << endl;
            cout << "Hardware factory flags (reserved): " << DUNE::Utils::String::str("0x%04X",(uint16_t) data_Beacon.cid_sys_info.hardware.flags_sys) << endl;
            cout << "Hardware user flags: " << DUNE::Utils::String::str("0x%04X",(uint16_t) data_Beacon.cid_sys_info.hardware.flags_user) << endl;
            cout << "Bootloader firmware validity: " << data_Beacon.cid_sys_info.boot_firmware.valid << endl;
            cout << "Bootloader firmware bootloader part number: " << data_Beacon.cid_sys_info.boot_firmware.part_number << endl;
            cout << "Bootloader firmware major version: " << data_Beacon.cid_sys_info.boot_firmware.version_maj << endl;
            cout << "Bootloader firmware minor version: " << data_Beacon.cid_sys_info.boot_firmware.version_min << endl;
            cout << "Bootloader firmware build version: " << data_Beacon.cid_sys_info.boot_firmware.version_build << endl;
            cout << "Bootloader firmware CRC32 checksum: " << data_Beacon.cid_sys_info.boot_firmware.checksum << endl;
            cout << "Main firmware validity: " << data_Beacon.cid_sys_info.main_firmware.valid << endl;
            cout << "Main firmware bootloader part number: " << data_Beacon.cid_sys_info.main_firmware.part_number << endl;
            cout << "Main firmware major version: " << data_Beacon.cid_sys_info.main_firmware.version_maj << endl;
            cout << "Main firmware minor version: " << data_Beacon.cid_sys_info.main_firmware.version_min << endl;
            cout << "Main firmware build version: " << data_Beacon.cid_sys_info.main_firmware.version_build << endl;
            cout << "Main firmware CRC32 checksum: " << data_Beacon.cid_sys_info.main_firmware.checksum << endl;
            break;

        // TODO (seems important for the USBL simulator!)
        // case CID_XCVR_USBL:
        //     data_Beacon.set(CID_XCVR_USBL);
        //     ind = ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_sig_peak, (const uint8_t*)msg_raw);
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_threshold, (const uint8_t*)&msg_raw[ind]);
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_cross_point, (const uint8_t*)&msg_raw[ind]);
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_cross_mag, (const uint8_t*)&msg_raw[ind]);
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_detect, (const uint8_t*)&msg_raw[ind]);
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_length, (const uint8_t*)&msg_raw[ind]);

        //     data_Beacon.cid_xcvr_usbl_msg.xcor_data.reserve(data_Beacon.cid_xcvr_usbl_msg.xcor_length);
        //     for(uint16_t i = 0; i < data_Beacon.cid_xcvr_usbl_msg.xcor_length; i++)
        //     {
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.xcor_data[i], (const uint8_t*)&msg_raw[ind]);
        //     }

        //     data_Beacon.cid_xcvr_usbl_msg.channels = msg_raw[ind++];
        //     data_Beacon.cid_xcvr_usbl_msg.channel_rssi.reserve(data_Beacon.cid_xcvr_usbl_msg.channels);
        //     for(uint16_t i = 0; i < data_Beacon.cid_xcvr_usbl_msg.channels; i++)
        //     {
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.channel_rssi[i], (const uint8_t*)&msg_raw[ind]);
        //     }

        //     data_Beacon.cid_xcvr_usbl_msg.baselines = msg_raw[ind++];
        //     data_Beacon.cid_xcvr_usbl_msg.phase_angle.reserve(data_Beacon.cid_xcvr_usbl_msg.baselines);
        //     for(uint16_t i = 0; i < data_Beacon.cid_xcvr_usbl_msg.baselines; i++)
        //     {
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.phase_angle[i], (const uint8_t*)&msg_raw[ind]);
        //     }
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.signal_azimuth, (const uint8_t*)&msg_raw[ind]);
        //     ind += ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.signal_elevation, (const uint8_t*)&msg_raw[ind]);
        //     ByteCopy::fromLE(data_Beacon.cid_xcvr_usbl_msg.signal_fit_error, (const uint8_t*)&msg_raw[ind]);
        //     break;

            // Should never get here.
        default:
            //m_data_state = DP_COMPLETE;
            break;
    }
}

/*** Helper functions ***/
// Parse Seatrac sentence (from buffer) into string (partially copied from Seatrac task)
// Returns length of 
int readSentence(double timeout)
{
    char data[16] = {0};
    int len = 0;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Read from input buffer bit by bit, as the modem sends data in chunks
    // A valid sentence is prefixed by $, and ends with \n\r
    // We must keep reading data until a valid sentence is obtained
    while(len < Transports::Seatrac::c_bfr_size){
        int rv = read(sock_fd, data, 1);
        if(data[0] == '\n')
            return len;
        else {
            if (data[0] == Transports::Seatrac::c_preamble){
                m_data.clear();
                clock_gettime(CLOCK_MONOTONIC, &end);
            } else if (data[0] != '\r'){
                m_data.push_back(*data);
                clock_gettime(CLOCK_MONOTONIC, &end);
                len++;
            }
        }
        if((end.tv_sec - start.tv_sec) > timeout){
            cout << "Timeout waiting for data" << endl;
            break;
        }
    }

    return 0;
}

// Signal handler for SIGINT (keyboard interrupt CTRL+C)
void sigint_handle(int sig){
    cout << "Interrupted, closing TCP socket" << endl;
    close(sock_fd);
    exit(0);
}

// Connect to IP address through TCP socket
int connect(const char *addr, int port, double timeout){
    // Set up TCP socket
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        cerr << "Error: Could not create socket" << endl;
        return 0;
    }

    // IP address of manta to which the acoustic modem is connected (temptive)
    if(inet_pton(AF_INET, addr, &servaddr.sin_addr)<=0){
        cerr << "Error: Invalid address or address not supported" << endl;
        close(sock_fd);
        return 0;
    }

    servaddr.sin_family    = AF_INET;                   // Indicates IPv4 address
    servaddr.sin_port      = htons(port);

    // Attempt connection to address for <timeout> seconds, if timeout is positive
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while(connect(sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        clock_gettime(CLOCK_MONOTONIC, &end);
        double elapsed = end.tv_sec - start.tv_sec;
        if (elapsed > timeout && timeout > 0){
            cerr << "Error: Timeout trying to connect to server" << endl;
            return 0;
        }
    }

    return 1;   // Connection successful
}

/*** Main ***/
int main(int argc, char **argv){
    // Attach handler to SIGINT
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = sigint_handle;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    
    if (argc < 3){
        cerr << "Error: Too few arguments" << endl;
        cout << "Usage: ./seatrac_listener <IP Address> <Port>" << endl; 
        exit(1);
    }

    cout << "Attempting connection to " << argv[1] << ":" << argv[2] << endl;
    if(!connect(argv[1], atoi(argv[2]), -1)){  // Attempt connection indefinitely
        close(sock_fd);
        exit(1);
    }
    cout << "Connection established to " << argv[1] << ":" << argv[2] << endl; 

    double timeout = 5.0;
    struct timespec last_recv, lap;
    while(true){
        // Output received message to string, without preamble
        // char bfr[Transports::Seatrac::c_bfr_size];
        // size_t rv = read( sock_fd, bfr, Transports::Seatrac::c_bfr_size);
        int len = readSentence(5.0);
        if (len > 0){
            // If CRC passes, parse the message and display it
            cout << endl << "[NEW MESSAGE]" << endl;
            cout << "Length: " << len << endl;
            cout << "Sentence: \"$" << m_data << "\"" << endl;
            
            // Get CRC from message
            uint16_t crc, crc2;
            string msg = DUNE::Utils::String::fromHex(m_data.substr((m_data.size() - 4), 4));
            memcpy(&crc2, msg.data(), 2);
            
            // Calculate CRC locally
            string m_datahex = DUNE::Utils::String::fromHex(m_data.erase((m_data.size() - 4), 4));
            crc = DUNE::Algorithms::CRC16::compute((uint8_t*) m_datahex.data(), m_datahex.size(),0);
            
            // If CRC fails, drop the message (do nothing)
            if (crc != crc2){
                cerr << "Error: Invalid CRC, message dropped" << endl;
            }
            else {
                const char *msg_raw = m_datahex.data();
                uint16_t typemes = 0;
                memcpy(&typemes, msg_raw, 1);
                Transports::Seatrac::DataSeatrac m_data_beacon;
                dataParser(typemes, msg_raw + 1, m_data_beacon);
                dataPrint(typemes, m_data_beacon);
                m_data.clear();
                m_datahex.clear();
            }
            clock_gettime(CLOCK_MONOTONIC, &last_recv);
        } else {
            // If no data was received from the server for some time,
            // assume a connection failure and attempt to reconnect
            clock_gettime(CLOCK_MONOTONIC, &lap);
            double elapsed = lap.tv_sec - last_recv.tv_sec;
            if (elapsed > timeout){
                cerr << "Timeout waiting for server, attempting reconnection" << endl;
                while(true){
                    close(sock_fd);         // Close socket so it can be reopened  
                    if(connect(argv[1], atoi(argv[2]), 1)){   // Try to connect for 1 second
                        cout << "Connection re-established" << endl;
                        break;
                    }
                }
            }
        }
    }

    // Catch-all close socket
    close(sock_fd);
    
    return 0;
}
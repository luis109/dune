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

// Socket definitions
int sock_fd; 
struct sockaddr_in servaddr; 
int addrlen = sizeof(servaddr);

/*** Helper functions ***/
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

void sendCommandTCP(Transports::Seatrac::CommandID cid, Transports::Seatrac::DataSeatrac& data_Beacon){
    const string cmd = Transports::Seatrac::commandCreateSeatrac(cid, data_Beacon);
    send(sock_fd , cmd.c_str() , strlen(cmd.c_str()) , 0);
    sleep(1);
}

void printInstructions(){
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "| ********* AHRS calibration procedure for Seatrac acoustic modem **********  |" << endl;
    cout << "| INSTRUCTIONS:                                                               |" << endl;
    cout << "|  1) Connect the Seatrac acoustic modem to a Manta IP modem (e.g., manta-21) |" << endl;
    cout << "|  2) If not already on, power up the Seatrac modem                           |" << endl;
    cout << "|  3) If not present, copy this source file to dune's \"programs/utils\" folder |" << endl;
    cout << "|  4) Compile dune with this program in the \"programs/utils\" folder           |" << endl;
    cout << "|  5) In dune's build directory, run this program passing the manta's IP and  |" << endl;
    cout << "|    port as arguments (i.e., ./seatrac_utils <IP> <Port>)                    |" << endl;
    cout << "|  6) Follow the on-screen instructions to perform calibration                |" << endl;
    cout << "|  7) Check the calibration's progress in the CID_STATUS messages coming from |" << endl;
    cout << "|    the modem. To see the messages, you can use the \"seatrac_listener\"       |" << endl;
    cout << "|    program, which must also be compiled along with dune as in steps 3 and 4 |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;    
}

/*** Main ***/
int main(int argc, char **argv){
    // Seatrac data structure
    Transports::Seatrac::DataSeatrac m_data_beacon;
    
    // Attach handler to SIGINT
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = sigint_handle;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    
    printInstructions();

    if (argc < 3){
        cerr << "Error: Too few arguments" << endl;
        cout << "Usage: ./seatrac_calib <IP Address> <Port>" << endl; 
        exit(1);
    }

    cout << "Attempting connection to " << argv[1] << ":" << argv[2] << endl;
    if(!connect(argv[1], atoi(argv[2]), -1)){  // Attempt connection indefinitely
        close(sock_fd);
        exit(1);
    }
    cout << "Connection established to " << argv[1] << ":" << argv[2] << endl; 

    // Calibrate AHRS accelerometer
    cout << endl << "----------------------------------------------" << endl;
    cout <<         "| ***** AHRS accelerometer calibration ***** |" << endl;
    cout <<         "----------------------------------------------" << endl;
    cout << " -> Please hold the Seatrac modem in an upright position, " << endl
         << "as shown in page 138 of the user manual." << endl;
    cout << "[PRESS ENTER TO CONTINUE]" << endl;
    cin.ignore();

    // Send CID_SETTINGS_SET command to modem, with ACC_CAL and AHRS_RAW_DATA
    m_data_beacon.cid_settings_msg.status_flags |= (1 << Transports::Seatrac::STATUS_MODE_10HZ);
    m_data_beacon.cid_settings_msg.status_output |=
        (~(1 << Transports::Seatrac::MAG_CAL_FLAG) | (1 << Transports::Seatrac::ACC_CAL_FLAG) | (1 << Transports::Seatrac::AHRS_RAW_DATA_FLAG));     // STATUSMODE_E = 10 Hz;    
    cout << " -> Sending CID_SETTINGS_SET command to modem" << endl;
    sendCommandTCP(Transports::Seatrac::CID_SETTINGS_SET, m_data_beacon);
    cout << " -> Done" << endl;

    // Send CID_CAL_ACTION command to modem
    m_data_beacon.cid_cal_action.action |= (1 << Transports::Seatrac::CAL_ACC_RESET);
    cout << " -> Sending CID_CAL_ACTION command to modem (CAL_ACC_RESET)" << endl;
    sendCommandTCP(Transports::Seatrac::CID_CAL_ACTION, m_data_beacon);
    cout << " -> Done" << endl;

    cout << endl << " -> Accelerometer calibration has started." << endl;
    cout << " -> Please slowly start moving the beacon around the "
         << "vertical position to find the maximum Z value." << endl;
    cout << "    The emphasis should be on slow and gentle movements to "
         << "avoid acceleration peaks from being detected." << endl;
    cout << " -> You can observe the maximum Z value for calibration "
         << "in the CID_STATUS message " << endl
         << "    (e.g., using the seatrac_listener program)." << endl;
    cout << " -> When done, press enter to continue." << endl;
    cout << "[PRESS ENTER TO CONTINUE]" << endl;
    cin.ignore();

    cout << " -> Please hold the beacon horizontally and slowly rotate it " << endl
         << "    clockwise and anti-clockwise to find the minimum and maximum " << endl
         << "    values for the X and Y axis." << endl;
    cout << " -> When done, press enter to continue." << endl;
    cout << "[PRESS ENTER TO CONTINUE]" << endl;
    cin.ignore();
    
    m_data_beacon.cid_cal_action.action |= (1 << Transports::Seatrac::CAL_ACC_CALC);
    cout << " -> Sending CID_CAL_ACTION command to modem (CAL_ACC_CALC)" << endl;
    sendCommandTCP(Transports::Seatrac::CID_CAL_ACTION, m_data_beacon);
    cout << " -> Done" << endl;

    char opt = 0x00;
    cout << endl << " -> Would you like to save the calibration parameters in the beacon's " 
        << "EEPROM memory? [y/n]" << endl;
    do{
        cin >> opt;
        switch (opt){
        case 'y':
            cout << " -> Sending CID_SETTINGS_SAVE command to modem" << endl;
            sendCommandTCP(Transports::Seatrac::CID_SETTINGS_SAVE, m_data_beacon);
            cout << " -> Done" << endl;
            break;
        case 'n':
            break;
        default:
            cout << " -> Unknown option \'" << opt << "\'" << endl;
        }
    } while((opt != 'y') && (opt != 'n'));

    // Calibrate AHRS magnetometer
    cout << endl << "----------------------------------------------" << endl;
    cout <<         "| ***** AHRS magnetometer calibration *****  |" << endl;
    cout <<         "----------------------------------------------" << endl;
    cout << " -> Please hold the Seatrac modem in an upright position, "
         << "as shown in page 138 of the user manual." << endl;
    cout << "[PRESS ENTER TO CONTINUE]" << endl;
    cin.ignore(); cin.ignore(); // Ugly, but it works...

    // Send CID_SETTINGS_SET command to modem, with MAG_CAL and AHRS_RAW_DATA
    m_data_beacon.cid_settings_msg.status_flags |= (1 << Transports::Seatrac::STATUS_MODE_10HZ);
    m_data_beacon.cid_settings_msg.status_output |=
        ((1 << Transports::Seatrac::MAG_CAL_FLAG) | ~(1 << Transports::Seatrac::ACC_CAL_FLAG) | (1 << Transports::Seatrac::AHRS_RAW_DATA_FLAG));     // STATUSMODE_E = 10 Hz;    
    cout << " -> Sending CID_SETTINGS_SET command to modem" << endl;
    sendCommandTCP(Transports::Seatrac::CID_SETTINGS_SET, m_data_beacon);
    cout << " -> Done" << endl;

    // Send CID_CAL_ACTION command to modem
    m_data_beacon.cid_cal_action.action |= (1 << Transports::Seatrac::CAL_MAG_RESET);
    cout << " -> Sending CID_CAL_ACTION command to modem (CAL_MAG_RESET)" << endl;
    sendCommandTCP(Transports::Seatrac::CID_CAL_ACTION, m_data_beacon);
    cout << " -> Done" << endl;

    cout << endl << " -> Magnetometer calibration has started." << endl;
    cout << " -> Please start rotating the beacon around all 3-axis in 3D space." << endl;
    cout << " -> As the beacon is rotated, the Pitch and Roll information is used to " << endl
         << "    build up a 3D magnetic map surrounding the beacon in the calibration buffer." << endl;
    cout << " -> You can observe the calibration progress in the in the CID_STATUS message" << endl
         << "    (e.g., using the seatrac_listener program)." << endl;
    cout << " -> When done, press enter to continue." << endl;
    cout << "[PRESS ENTER TO CONTINUE]" << endl;
    cin.ignore();
    
    m_data_beacon.cid_cal_action.action |= (1 << Transports::Seatrac::CAL_MAG_CALC);
    cout << " -> Sending CID_CAL_ACTION command to modem (CAL_MAG_CALC)" << endl;
    sendCommandTCP(Transports::Seatrac::CID_CAL_ACTION, m_data_beacon);
    cout << " -> Done" << endl;
    
    opt = 0x00;
    cout << endl << " -> Would you like to save the calibration parameters in the beacon's " 
        << "EEPROM memory? [y/n]" << endl;
    do{
        cin >> opt;
        switch (opt){
        case 'y':
            cout << " -> Sending CID_SETTINGS_SAVE command to modem" << endl;
            sendCommandTCP(Transports::Seatrac::CID_SETTINGS_SAVE, m_data_beacon);
            cout << " -> Done" << endl;
            break;
        case 'n':
            break;
        default:
            cout << " -> Unknown option \'" << opt << "\'" << endl;
        }
    } while((opt != 'y') && (opt != 'n')); 

    cout << endl << " -> Calibration finished sucessfully!" << endl;

    close(sock_fd);
    
    return 0;
}
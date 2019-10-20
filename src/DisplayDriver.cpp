/*
 * DisplayDriver.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#include "../include/DisplayDriver.h"
#include <chrono>
#include <thread>
#include <bitset>

DisplayDriver::DisplayDriver() {
    register_select = GPIO(1012);
    read_write = GPIO(1013);
    enable = GPIO(1014);

    data_bit[0] = GPIO(1016);
    data_bit[1] = GPIO(1017);
    data_bit[2] = GPIO(1018);
    data_bit[3] = GPIO(1019);
    data_bit[4] = GPIO(1020);
    data_bit[5] = GPIO(1021);
    data_bit[6] = GPIO(1022);
    data_bit[7] = GPIO(1023);

}

DisplayDriver::~DisplayDriver() {
    for (int i = 0; i < 12; ++i) {
        data_bit[i].unexportPin();
    }
    register_select.unexportPin();
    read_write.unexportPin();
    enable.unexportPin();
}

int DisplayDriver::initGPIOs() {
    for (int i = 0; i < 4; ++i) {
        data_bit[i].exportPin();
        data_bit[i].setPinDirection("out");;
    }
    register_select.exportPin();
    register_select.setPinDirection("out"); //High for data transfer low for instruction transfer

    read_write.exportPin(); //high for read mode, low for write mode
    read_write.setPinDirection("out");

    enable.exportPin();             //read/write enable
    enable.setPinDirection("out");  //High for read, falling edge writes data
    return 0;
}

int DisplayDriver::initDisplay() {

    std::chrono::milliseconds mil(1);
    std::this_thread::sleep_for(mil*50);    //set function
    sendCommand("Function Set");

    std::this_thread::sleep_for(mil);       //display set
    sendCommand("Display Set");

    std::this_thread::sleep_for(mil);       //display clear
    sendCommand("Clear Display");

    std::this_thread::sleep_for(mil*20);
    sendCommand("Entry Mode");

    return 0;
}

int DisplayDriver::init() {
    initGPIOs();
    initDisplay();
    return 0;
}

int DisplayDriver::print(int number, std::string data) { //not sure what the int should do
    sendData(data);
    return 0;
}


int DisplayDriver::clear(){
    sendCommand("Clear Display"); //entry mode aswell??
    return 0;
}

int DisplayDriver::pulseEnableSignal() {
    enable.setPinValue("1");
    enable.setPinValue("0");
    return 0;
}

int DisplayDriver::sendData(std::string data) {     //send en string som skal skrives på display
    for (int i = 0; i < data.length(); ++i) {

        std::bitset<8> foo (data.at(i));
        setDataBits("10"+ foo.to_string());
        pulseEnableSignal();
    }
    return 0;
}


int DisplayDriver::setDataBits(std::string databits) {  //send to display or to write stuff or to use commands one Char at a time
    if(databits.length() != 10) {
        std::cout << "invalid length of databits" << std::endl;
        return 0;
    }

    register_select.setPinValue(databits.at(0));
    read_write.setPinValue(databits.at(1));

    for (int i = 0; i < 8; ++i) {
        data_bit[i].setPinValue(databits.at(i+2));
    }

    return 0;
}


int DisplayDriver::sendCommand(std::string command) {  //check reference-manual Pmod CLP instruction codes
    if(command == "Clear Display"){ //0000 0000 01
        setDataBits("0000000001");
    }

    if(command == "Return Home"){ //0000 0000 1x
        setDataBits("0000000010");
    }

    if(command == "Display Set"){  //0000 0011 11
        setDataBits("0000001111");
    }

    if(command == "Function Set"){//0000 1110 xx
        setDataBits("0000111000");
    }

    if(command == "Entry Mode"){  //0000 0001 10
        setDataBits("0000000110");
    }

    else{
        std::cout << "invalid command: " << command << std::endl;
        return -1;
    }

    pulseEnableSignal();
    return 0;
}

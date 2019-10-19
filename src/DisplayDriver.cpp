/*
 * DisplayDriver.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#include "../include/DisplayDriver.h"
#include "../../../../../usr/include/c++/7/chrono"
#include <chrono>

DisplayDriver::DisplayDriver() {
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
    mil = mil*50;
    std::cout << "duration test" << mil.count() << std::endl;

    return 0;
}

int DisplayDriver::init() {
    initGPIOs();
    initDisplay();
    return 0;
}

int DisplayDriver::print(int number, std::string string) {

    return 0;
}


int DisplayDriver::clear(){
    return 0;
}

int DisplayDriver::pulseEnableSignal() {
    enable.setPinValue("1");
    enable.setPinValue("0");
    return 0;
}

int DisplayDriver::sendData(std::string data) {
    return 0;
}

int DisplayDriver::sendData(char _char) {
    return 0;
}

int DisplayDriver::sendCommand(std::string command) {
    return 0;
}

int DisplayDriver::setDataBits(int bitset) {
    return 0;
}

int DisplayDriver::setDataBits(std::string databits) {

    return 0;
}


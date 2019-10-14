/*
 * GPIO.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#include "../include/GPIO.h"
#include <string>
GPIO::GPIO(){

};

GPIO::GPIO(int pin_num, std::string direction){
	setPinNumber(pin_num);
	exportPin();
	setPinDirection(direction);
}

int GPIO::writeToFile(std::string path, std::string input){
    std::ofstream path_file( path );
    if(!path_file.is_open())
    {
        std::cerr << "Unable to open " << path << std::endl;
        return -1;
    }
    path_file << input << std::endl;
    path_file.close();
    return 0;
}

int GPIO::readFromFile(std::string path, std::string& output) {
    std::ifstream read_file( path );
    if(!read_file.is_open())
    {
        std::cerr << "Unable to open " << path << std::endl;
        return -1;
    }
    read_file >> output;
    return 0;
}

int GPIO::setPinNumber(int num){
	pin_number = std::to_string(num);
	return 1;
}

int GPIO::getPinNumber(){
    return std::stoi(pin_number);
}

int GPIO::exportPin() {
    std::string export_path = "/sys/class/gpio/export";
    writeToFile(export_path, pin_number);
    return 0;
}

int GPIO::unexportPin() {
    std::string unexport_path = "/sys/class/gpio/unexport";
    writeToFile(unexport_path, pin_number);
    return 0;
}

int GPIO::setPinDirection(std::string direction) {
    std::string file = "/sys/class/gpio/gpio" + pin_number + "/direction";
    writeToFile(file,direction);
    return 0;
}

int GPIO::setPinValue(std::string value) {
    std::string file = "/sys/class/gpio/gpio" + pin_number + "/value";
    writeToFile(file,value);
    return 0;
}

int GPIO::getPinValue(std::string &output) {
    std::string file = "/sys/class/gpio/gpio" + pin_number + "/value";
    readFromFile(file, output);
    if(output == "1")
        return 1;
    else if(output == "0")
        return 0;
    else
        return -1;
}

void GPIO::clear(void) {
    setPinValue("0");
}

void GPIO::set(void) {
    setPinValue("1");
}


GPIO::~GPIO() {
	unexportPin();
}


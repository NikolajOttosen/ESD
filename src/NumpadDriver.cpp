/*
 * NumpadDriver.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#include "../include/NumpadDriver.h"

NumpadDriver::NumpadDriver() {
    //init();
}

NumpadDriver::~NumpadDriver() {
	// TODO Auto-generated destructor stub
}

int NumpadDriver::init() {
    GPIO COL4;
    std::cout << "init()" << std::endl;
    //GPIO COL4(992,"out");
    //GPIO COL3(993,"out");

    COL4.setPinNumber(992);
    COL4.

    GPIO COL3;
    COL3.setPinNumber(993);
    COL3.exportPin();
    COL3.setPinValue("out");

    std::cout << "export??" << std::endl;
    GPIO COL2(994,"out");
    GPIO COL1(995,"out");

    GPIO ROW4(996,"in");
    GPIO ROW3(997,"in");
    GPIO ROW2(998,"in");
    GPIO ROW1(999,"in");

    column[0] = COL4;
    column[1] = COL3;
    column[2] = COL2;
    column[3] = COL1;

    row[0] = ROW4;
    row[1] = ROW3;
    row[2] = ROW2;
    row[3] = ROW1;

    matrix =  {
            {"1", "2", "3", "A"},
            {"4", "5", "6", "B"},
            {"7", "8", "9", "C"},
            {"0", "F", "E", "D"}
    };

    return 0;
}

std::string NumpadDriver::check() {
    return getValue();
}

std::string NumpadDriver::getValue() {
    std::string output;
    int temp_i = 9;
    int temp_j = 9;
    for (int i = 0; i < 4; ++i) {
        column[i].setPinValue("0");

        for (int j = 0; j < 4; ++j) {

            if (!row[j].getPinValue(output))
            {
                return matrix[i][j];

            }
        }

        column[i].setPinValue("1");
    }

    return "string";
}

GPIO NumpadDriver::getGPIO() {
    return column[0];
}


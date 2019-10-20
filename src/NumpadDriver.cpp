/*
 * NumpadDriver.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#include "../include/NumpadDriver.h"

NumpadDriver::NumpadDriver() {
    column[3] = GPIO(992);
    column[2] = GPIO(993);
    column[1] = GPIO(994);
    column[0] = GPIO(995);

    row[3] = GPIO(996);
    row[2] = GPIO(997);
    row[1] = GPIO(998);
    row[0] = GPIO(999);

    matrix =  {
            {"1", "4", "7", "0"},
            {"2", "5", "8", "F"},
            {"3", "6", "9", "E"},
            {"A", "B", "C", "D"}
    };
}

NumpadDriver::~NumpadDriver() {
    for (int i = 0; i < 4; ++i) {
        column[i].unexportPin();
        row[i].unexportPin();
    }
}

int NumpadDriver::init() {
    for (int i = 0; i < 4; ++i) {
        column[i].exportPin();
        column[i].setPinDirection("out");
        row[i].exportPin();
        row[i].setPinDirection("in");
    }

    return 0;
}

std::string NumpadDriver::check() {
    return getValue();
}

std::string NumpadDriver::getValue() {
    std::string output;


    for (int i = 0; i < 4; ++i) {

        column[0].setPinValue("1");
        column[1].setPinValue("1");
        column[2].setPinValue("1");
        column[3].setPinValue("1");
        column[i].setPinValue("0");

        for (int j = 0; j < 4; ++j) {

            if (row[j].getPinValue(output) == 0)
            {
                return matrix[i][j];
            }
        }
    }

    return "NULL";
}


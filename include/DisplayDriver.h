/*
 * DisplayDriver.h
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#ifndef DISPLAYDRIVER_H_
#define DISPLAYDRIVER_H_

#include "GPIO.h"

class DisplayDriver {
public:
	DisplayDriver();
    int init();
    int print(int, std::string);
    static int clear();

	virtual ~DisplayDriver();
private:
    int initGPIOs();
    int initDisplay();
    int setDataBits(std::string databits);
    int setDataBits(int bitset);
    int pulseEnableSignal();
    int sendCommand(std::string command);
    int sendData(std::string data);
    int sendData(char _char);

    GPIO data_bit[8];
    GPIO register_select = GPIO(1012);
    GPIO read_write = GPIO(1013);
    GPIO enable = GPIO(1014);

};

#endif /* DISPLAYDRIVER_H_ */

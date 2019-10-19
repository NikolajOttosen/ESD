/*
 * NumpadDriver.h
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#ifndef NUMPADDRIVER_H_
#define NUMPADDRIVER_H_

#include "GPIO.h"
#include <string>
#include <vector>

class NumpadDriver : GPIO {
public:
	NumpadDriver();
	int init();
    std::string check();
	virtual ~NumpadDriver();

private:
    std::string getValue();

    GPIO column [4];
    GPIO row [4];
    std::vector< std::vector <std::string>> matrix;
};

#endif /* NUMPADDRIVER_H_ */

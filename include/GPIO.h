/*
 * Gpio.h
 *
 *  Created on: Oct 8, 2019
 *      Author: nikolaj
 */

#ifndef PERIPHERALS_GPIO_HPP_
#define PERIPHERALS_GPIO_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>


class GPIO
{
private:
    std::string pin_number;

    int writeToFile(std::string, std::string);
    int readFromFile(std::string, std::string&);

public:
    GPIO();
    GPIO(int pin_num, std::string direction);

    int setPinNumber(int);
    int getPinNumber();

    int exportPin();
    int unexportPin();

    int setPinDirection(std::string);

    int setPinValue(std::string);
    int getPinValue(std::string& );

    void set(void);
    void clear(void);
    ~GPIO();
};

#endif /* PERIPHERALS_GPIO_HPP_ */

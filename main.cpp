//============================================================================
// Name        : esd.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include "include/DisplayDriver.h"
#include "include/NumpadDriver.h"
#include "include/GPIO.h"
using namespace std;


int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
/*  GPIO gpio_led;
    gpio_led.setPinNumber(984);
    gpio_led.exportPin();
    gpio_led.setPinDirection("out");

    GPIO gpio_btn;
    gpio_btn.setPinNumber(988);
    gpio_btn.exportPin();
    gpio_btn.setPinDirection("in"); */

    //GPIO gpio_led(984,"out");
    GPIO gpio_btn(988,"in");

    GPIO gpio_led;
    gpio_led.setPinNumber(984);
    gpio_led.exportPin();
    gpio_led.setPinDirection("out");


    NumpadDriver npd;
    npd.init();

    std:string pin_value;
    while(true){
        //gpio_btn.getPinValue(pin_value);

        if(gpio_btn.getPinValue(pin_value))
            gpio_led.set();
        else
            gpio_led.clear();

       // std::cout << npd.check() << std::endl;
    }
	return 0;
}


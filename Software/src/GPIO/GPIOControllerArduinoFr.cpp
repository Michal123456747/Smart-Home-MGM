/**
 * @file GPIOControllerArduinoFr.cpp
 * @brief Contains codes for the methods of the GPIOControllerArduinoFr class
 */

#include <Arduino.h>
#include <algorithm>

#include "GPIOControllerArduinoFr.hpp"

bool GPIOManage::GPIOControllerArduinoFr::ReservePin(uint8_t pinNum, PinType type, PinMode mode) // reserve pin
{
    if(std::any_of(pins_.begin(), pins_.end(), [pinNum](Pin i){return i.number_ == pinNum;})){ // if pin is already reserved return false
        return false;
    }

    if(mode == OUTPUT_){
        pinMode(pinNum, OUTPUT);    // pin reservation
    }
    else if (mode == INPUT_){
        pinMode(pinNum, INPUT);
    }
    else{
        pinMode(pinNum, INPUT_PULLUP);
    }

    Pin reserved(pinNum, type, mode);    // creating a PIN object
    pins_.push_back(reserved);     // adding pin to vector

    return true;
}

unsigned int GPIOManage::GPIOControllerArduinoFr::ReadFromPin(uint8_t pinNum)    // reading value from pin
{
    uint8_t pin_location = 0;
    bool found = false;
    while(pin_location < pins_.size())     // finding pin in the vector
    {
        if(pins_.at(pin_location).number_ == pinNum)  // if pin number is the same
        {
            found = true;   // that means we found it
            break;
        }
        ++pin_location;
    }

    if(found)   // if we found pin in vector
    {
        if(pins_.at(pin_location).type_ == DIGITAL_)    // if type is digital
        {
            if(digitalRead(pinNum) == HIGH){   // return 0 or 1
                return 1;
            }
            return 0;
        }
        else    // if type is analog
        {
            return analogRead(pinNum); // return value from 0 to 1023
        }
    }

    return 0;
}

bool GPIOManage::GPIOControllerArduinoFr::WriteToPin(uint8_t pinNum, bool value)  // set to pin for digital type
{
    uint8_t pin_location = 0;
    bool found = false;
    while(pin_location < pins_.size())     // finding pin in the vector
    {
        if(pins_.at(pin_location).number_ == pinNum)  // if pin number is the same
        {
            found = true;   // that means we found it

            if(pins_.at(pin_location).type_ != DIGITAL_){  // if not digital
                return false;
            }

            if(value){
                digitalWrite(pinNum, HIGH);   // setting value to pin
            }
            else{
                digitalWrite(pinNum, LOW);
            }

            break;
        }
        ++pin_location;
    }

    return found;       // if pin is not reserved return false
}

bool GPIOManage::GPIOControllerArduinoFr::WriteToPin(uint8_t pinNum, unsigned int value) // set to pin for analog type
{
    if(value >= 1024){   // analog value can be from 0 to 1023
        return false;
    }

    uint8_t pin_location = 0;
    bool found = false;
    while(pin_location < pins_.size())     // finding pin in the vector
    {
        if(pins_.at(pin_location).number_ == pinNum)  // if pin number is the same
        {
            found = true;   // that means we found it

            if(pins_.at(pin_location).type_ != ANALOG_){  // if not analog
                return false;
            }

            analogWrite(pinNum, value);   // setting value to pin

            break;
        }
        ++pin_location;
    }

    return found;       // if pin is not reserved return false
}

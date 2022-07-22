#pragma once


#include <Arduino.h>
#include <vector>


namespace GPIO
{

#define NUM_ 0
#define TYPE_ 1     // for PIN::check
#define STATUS_ 2

#define DIGITAL_ 0  // for GPIOArduinoController::reserve_pin
#define ANALOG_ 1

#define OUTPUT_ 0
#define INPUT_ 1    // for GPIOArduinoController::reserve_pin
#define INPUT_PULLUP_ 2

class GPIOController
{
    virtual bool reserve_pin(byte, byte, byte) = 0;
    virtual unsigned int read_from_pin(byte) = 0;
    virtual bool set_to_pin(byte, bool) = 0;
    virtual bool set_to_pin(byte, unsigned int) = 0;
};

class PIN   // WARNING: no data control - use only in other classes
{
    byte number_;
    byte type_;     // digital or analog - should be 0 or 1
    byte status_;   // input, output or input pullup - should be from 0 to 2

public:
    PIN(byte, byte, byte);  // input is pin number, pin type and pin status - constructor

    byte check(byte); // input 0, 1 or 2 - used to check the pin number, type or status

    ~PIN() = default;
};

class GPIOArduinoController: public GPIOController
{
    std::vector<PIN> pins_reserved_;    // list of pins already reserved
public:
    GPIOArduinoController() = default;

    virtual bool reserve_pin(byte, byte, byte)  override;   // input - pin number, pin type and pin status  - pin reservation
    virtual unsigned int read_from_pin(byte)    override;   // input - pin number                           - reading value from pin
    virtual bool set_to_pin(byte, bool)         override;   // input - pin number, value (false or true)    - setting value for digital pin
    virtual bool set_to_pin(byte, unsigned int) override;   // input - pin number, value (from 0 to 1023)   - setting value for analog pin

    ~GPIOArduinoController() = default;
};

}
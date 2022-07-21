#pragma once


#include <Arduino.h>
#include <vector>


namespace GPIO
{

#define NUM_ 0
#define TYPE_ 1     // for PIN::check
#define STATUS_ 2

#define PWM_ 0
#define DIGITAL_ 1  // for GPIOArduinoController::reserve_pin
#define ANALOG_ 2

#define INPUT_ true // for GPIOArduinoController::reserve_pin
#define OUTPUT_ false

class GPIOController
{
    virtual bool reserve_pin(byte, byte, bool) = 0;
    virtual unsigned int read_from_pin(byte) = 0;
    virtual bool set_to_pin(byte, bool) = 0;
    virtual bool set_to_pin(byte, unsigned int) = 0;
};

class PIN
{
    byte number_;
    byte type_;
    bool status_;

public:
    PIN(byte, byte, bool);

    byte check(byte); // 0, 1 or 2

    ~PIN() = default;
};

class GPIOArduinoController: public GPIOController
{
    std::vector<PIN> pins_reserved_;
public:
    GPIOArduinoController() = default;

    virtual bool reserve_pin(byte, byte, bool)  override;
    virtual unsigned int read_from_pin(byte)    override;
    virtual bool set_to_pin(byte, bool)         override;
    virtual bool set_to_pin(byte, unsigned int) override;

    ~GPIOArduinoController() = default;
};

}
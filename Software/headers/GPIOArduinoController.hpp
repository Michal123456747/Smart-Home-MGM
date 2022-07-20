#pragma once


#include <Arduino.h>
#include <vector>


namespace GPIO
{

#define NUM 0
#define TYPE 1
#define STATUS 2

#define PWM 0
#define DIGITAL 1
#define ANALOG 2

class GPIOController
{
    virtual bool reserve_pin() = 0;
    virtual unsigned int read_from_pin() = 0;
    virtual void set_to_pin() = 0;
};

class PIN
{
    byte number_;
    byte type_;
    bool status_;

public:
    PIN(byte, byte, bool);



    ~PIN() = default;
};

class GPIOArduinoController: public GPIOController
{
    std::vector<PIN> pins_reserved_;
public:
    GPIOArduinoController() = default;

    virtual bool reserve_pin(byte, byte, bool) override;
    virtual unsigned int read_from_pin(byte) override;
    virtual void set_to_pin(byte) override;

    ~GPIOArduinoController() = default;
};

}
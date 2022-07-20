#pragma once



#include <Arduino.h>
#include <vector>

namespace GPIO
{

class GPIOController
{
    virtual bool reserve_pin(byte, byte, bool) = 0;
    virtual unsigned int read_from_pin(byte) = 0;
    virtual void set_to_pin(byte) = 0;
};

struct PIN
{
    byte number;
    byte type;
    bool status;
};

class GPIOArduinoController: public GPIOController
{
    std::vector<PIN> pins_reserved;
public:
    GPIOArduinoController();

    virtual bool reserve_pin(byte, byte, bool) override;
    virtual unsigned int read_from_pin(byte) override;
    virtual void set_to_pin(byte) override;

    ~GPIOArduinoController();
};

}
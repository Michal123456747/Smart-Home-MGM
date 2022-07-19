#pragma once



#include <Arduino.h>

class GPIOArduinoController
{

public:
    GPIOArduinoController();

    bool reserve_pin(byte, byte);
    unsigned int read_from_pin(byte);
    void set_to_pin(byte);
    void set_to_pin(byte);

    ~GPIOArduinoController();
};

#include "/home/greggy/projekty_linux/smart-home-mgm/Software/Software/headers/GPIOArduinoController.hpp" // to change

GPIO::PIN::PIN(byte pin_num, byte type, bool status)
    : number_(pin_num),
    type_(type),
    status_(status)
    {}

bool GPIO::GPIOArduinoController::reserve_pin(byte pin_num, byte type, bool status)
{
    if(type < 3)
        return false;
    /*
    type:           status:
    0 - pwm         true - input
    1 - digital     false - output
    2 - analog
    */

    for(auto i : pins_reserved_)
    {
        if(i.number_ == pin_num)
            return false;
    }

    PIN reserved;


    return true;
}
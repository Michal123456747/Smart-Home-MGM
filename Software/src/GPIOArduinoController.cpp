
#include "/home/greggy/projekty_linux/smart-home-mgm/Software/Software/headers/GPIOArduinoController.hpp" // to change

GPIO::PIN::PIN(byte pin_num, byte type, bool status)
    : number_(pin_num),
    type_(type),
    status_(status)
    {}

byte GPIO::PIN::check(byte what)
{
    switch (what)
    {
    case 0:
        return number_;
    case 1:
        return type_;
    case 2:
        return status_;
    default:
        break;
    }
}

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
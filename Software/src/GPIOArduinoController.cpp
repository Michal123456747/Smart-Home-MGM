
#include "/home/greggy/projekty_linux/smart-home-mgm/Software/Software/headers/GPIOArduinoController.hpp" // to change

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

    for(auto i : pins_reserved)
    {
        if(i.number == pin_num)
            return false;
    }

    

    return true;
}
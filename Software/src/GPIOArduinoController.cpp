
#include "/home/greggy/projekty_linux/smart-home-mgm/Software/Software/headers/GPIOArduinoController.hpp" // to change

GPIO::PIN::PIN(byte pin_num, byte type, byte status)    // PIN constructor
    : number_(pin_num),
    type_(type),
    status_(status)
    {}

byte GPIO::PIN::check(byte what)    // check the PIN variables
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

bool GPIO::GPIOArduinoController::reserve_pin(byte pin_num, byte type, byte status) // reserve pin
{
    if(type >= 2 || status >= 3)    // there are only 2 types and 3 possible status
        return false;
    /*
    type:           status:
    0 - digital     0 - output
    1 - analog      1 - input
    .               2 - input pullup
    */

    for(auto i : pins_reserved_)    // if pin is already reserved return false
    {
        if(i.check(NUM_) == pin_num)
            return false;
    }

    if(status == 0)
        pinMode(pin_num, OUTPUT);    // pin reservation
    else if (status == 1)
        pinMode(pin_num, INPUT);
    else
        pinMode(pin_num, INPUT_PULLUP);

    PIN reserved(pin_num, type, status);    // creating a PIN object
    pins_reserved_.push_back(reserved);     // adding pin to vector

    return true;
}

bool GPIO::GPIOArduinoController::set_to_pin(byte pin_num, bool value)  // set to pin for digital type
{
    byte pin_location = 0;
    bool found = false;
    while(pin_location < pins_reserved_.size())     // finding pin in the vector
    {
        if(pins_reserved_.at(pin_location).check(NUM_) == pin_num)  // if pin number is the same
        {
            found = true;   // that means we found it

            if(pins_reserved_.at(pin_location).check(TYPE_) != DIGITAL_)  // if not digital
                return false;

            if(value)
                digitalWrite(pin_num, HIGH);   // setting value to pin
            else
                digitalWrite(pin_num, LOW);

            break;
        }
        ++pin_location;
    }

    return found;       // if pin is not reserved return false
}

bool GPIO::GPIOArduinoController::set_to_pin(byte pin_num, unsigned int value) // set to pin for analog type
{
    if(value >= 1024)   // analog value can be from 0 to 1023
        return false;

    byte pin_location = 0;
    bool found = false;
    while(pin_location < pins_reserved_.size())     // finding pin in the vector
    {
        if(pins_reserved_.at(pin_location).check(NUM_) == pin_num)  // if pin number is the same
        {
            found = true;   // that means we found it

            if(pins_reserved_.at(pin_location).check(TYPE_) != ANALOG_)  // if not analog
                return false;

            analogWrite(pin_num, value);   // setting value to pin

            break;
        }
        ++pin_location;
    }

    return found;       // if pin is not reserved return false
}
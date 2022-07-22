/**
 * @file GPIOArduinoController.hpp
 * @brief 
 */

//TODO: update descriptions

#include <vector>
#include <stdint.h>

#include "Pin.hpp"
#include "EGPIOTypes.hpp"
#include "AGPIOController.hpp"

#pragma once

namespace GPIO
{

// #define NUM_ 0
// #define TYPE_ 1     // for PIN::check
// #define STATUS_ 2

// #define DIGITAL_ 0  // for GPIOArduinoController::reserve_pin
// #define ANALOG_ 1

// #define OUTPUT_ 0
// #define INPUT_ 1    // for GPIOArduinoController::reserve_pin
// #define INPUT_PULLUP_ 2

// class GPIOController
// {
//     virtual bool reserve_pin(byte, byte, byte) = 0;
//     virtual unsigned int read_from_pin(byte) = 0;
//     virtual bool set_to_pin(byte, bool) = 0;
//     virtual bool set_to_pin(byte, unsigned int) = 0;
// };

    /**
     * @brief 
     * 
     */
    class GPIOControllerArduinoFr: public AGPIOController
    {
    public:
        GPIOControllerArduinoFr() = default;
        ~GPIOControllerArduinoFr() = default;

        /**
         * @brief 
         * 
         * @param pinNum 
         * @param type 
         * @param mode 
         * @return true 
         * @return false 
         */
        virtual bool ReservePin(uint8_t pinNum, PinType type, PinMode mode)  override;   // input - pin number, pin type and pin status  - pin reservation
        
        /**
         * @brief 
         * 
         * @param pinNum 
         * @return unsigned int 
         */
        virtual unsigned int ReadFromPin(uint8_t pinNum)    override;   // input - pin number                           - reading value from pin
        
        /**
         * @brief 
         * 
         * @param pinNum 
         * @param value 
         * @return true 
         * @return false 
         */
        virtual bool WriteToPin(uint8_t pinNum, bool value)         override;   // input - pin number, value (false or true)    - setting value for digital pin
        
        /**
         * @brief 
         * 
         * @param pinNum 
         * @param value 
         * @return true 
         * @return false 
         */
        virtual bool WriteToPin(uint8_t pinNum, unsigned int value) override;   // input - pin number, value (from 0 to 1023)   - setting value for analog pin

    private:
        std::vector<Pin> pins;    // list of pins already reserved
    };

}   // namespace GPIO

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
        virtual bool ReservePin(uint8_t pinNum, PinType type, PinMode mode) override;   // pin reservation
        
        /**
         * @brief 
         * 
         * @param pinNum 
         * @return unsigned int 
         */
        virtual unsigned int ReadFromPin(uint8_t pinNum) override;   // reading value from pin
        
        /**
         * @brief 
         * 
         * @param pinNum 
         * @param value 
         * @return true 
         * @return false 
         */
        virtual bool WriteToPin(uint8_t pinNum, bool value) override;   // setting value for digital pin
        
        /**
         * @brief 
         * 
         * @param pinNum 
         * @param value 
         * @return true 
         * @return false 
         */
        virtual bool WriteToPin(uint8_t pinNum, unsigned int value) override;   // setting value for analog pin

    private:
        std::vector<Pin> pins_;    // list of pins already reserved
    };

}   // namespace GPIO

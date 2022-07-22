/**
 * @file GPIOController.hpp
 * @brief 
 */

#include <stdint.h>

#include "EGPIOTypes.hpp"

#pragma once 

//TODO: Update descriptions
namespace GPIO
{
    class GPIOController
    {
        /**
         * @brief 
         * 
         * @param pinNum 
         * @param type 
         * @param mode 
         * @return false on fail 
         */
        virtual bool ReservePin(uint8_t pinNum, PinType type, PinMode mode) = 0;

        /**
         * @brief 
         * 
         * @param pinNum 
         * @return unsigned int 
         */
        virtual unsigned int ReadFromPin(uint8_t pinNum) = 0;

        /**
         * @brief 
         * 
         * @param pinNum 
         * @param value 
         * @return false on fail 
         */
        virtual bool WriteToPin(uint8_t pinNum, bool value) = 0;

        /**
         * @brief 
         * 
         * @param pinNum 
         * @param value 
         * @return false on fail 
         */
        virtual bool WriteToPin(uint8_t pinNum, unsigned int value) = 0;
    };
}   // namespace GPIO

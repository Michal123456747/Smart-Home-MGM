/**
 * @copydoc AWifiController::AddParameter
 */

#include <stdint.h>

#include "EGPIOTypes.hpp"

#pragma once

namespace GPIO
{
    class AGPIOController
    {
    public:
        /**
         * @brief A virtual method used to reserve a pin
         *
         * @param pinNum
         * @param type
         * @param mode
         * @return false on fail
         */
        virtual bool ReservePin(uint8_t pinNum, PinType type, PinMode mode) = 0;

        /**
         * @brief A virtual method used to read a value from a pin
         *
         * @param pinNum
         * @return unsigned int
         */
        virtual unsigned int ReadFromPin(uint8_t pinNum) = 0;

        /**
         * @brief A virtual method used to set a digital pin to a given value
         *
         * @param pinNum
         * @param value
         * @return false on fail
         */
        virtual bool WriteToPin(uint8_t pinNum, bool value) = 0;

        /**
         * @brief A virtual method used to set an analog pin to a given value
         *
         * @param pinNum
         * @param value
         * @return false on fail
         */
        virtual bool WriteToPin(uint8_t pinNum, unsigned int value) = 0;
    };
}   // namespace GPIO

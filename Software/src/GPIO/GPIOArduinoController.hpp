/**
 * @file GPIOArduinoController.hpp
 * @brief A header in which the GPIOControllerArduinoFr class publicly inheriting from the AGPIOController abstract class is declared
 */

#include <vector>
#include <stdint.h>

#include "Pin.hpp"
#include "EGPIOTypes.hpp"
#include "AGPIOController.hpp"

#pragma once

namespace GPIOManage
{
    /**
     * @brief Class responsible for controlling readings, values and pin reservations for Arduino
     *
     */
    class GPIOControllerArduinoFr: public AGPIOController
    {
    public:
        GPIOControllerArduinoFr() = default;
        ~GPIOControllerArduinoFr() = default;

        /**
         * @brief Method used to reserve a pin
         *
         * @param pinNum
         * @param type
         * @param mode
         * @return true on success
         * @return false on fail
         */
        bool ReservePin(uint8_t pinNum, PinType type, PinMode mode) override;   // pin reservation

        /**
         * @brief Method used to read a value from a pin - 0 or 1 if pin is digital, from 0 to 1023 if pin is analog
         *
         * @param pinNum
         * @return unsigned int
         */
        unsigned int ReadFromPin(uint8_t pinNum) override;   // reading value from pin

        /**
         * @brief Overloaded method used to set a digital pin to a given value
         *
         * @param pinNum
         * @param value
         * @return true on success
         * @return false on fail
         */
        bool WriteToPin(uint8_t pinNum, bool value) override;   // setting value for digital pin

        /**
         * @brief Overloaded method used to set a analog pin to a given value
         *
         * @param pinNum
         * @param value
         * @return true on success
         * @return false on fail
         */
        bool WriteToPin(uint8_t pinNum, unsigned int value) override;   // setting value for analog pin

    private:
        std::vector<Pin> pins_;    // list of pins already reserved
    };

}   // namespace GPIOManage

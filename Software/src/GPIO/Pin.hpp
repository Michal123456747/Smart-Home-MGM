/**
 * @file Pin.hpp
 * @brief Contains all data about pin configuration
 */

#include <stdint.h>

#include "EGPIOTypes.hpp"

#pragma once

namespace GPIOManage
{
    /**
     * @brief Type that contains all data about pin configuration
     */
    struct Pin
    {
        const uint8_t number_;
        const PinType type_;
        const PinMode mode_;

        Pin(uint8_t number, PinType type, PinMode mode)
        : number_(number), type_(type), mode_(mode)
        {}
    };
} // namespace GPIOManage

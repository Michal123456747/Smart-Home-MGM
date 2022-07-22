/**
 * @file EGPIOTypes.hpp
 * @brief Types used by GPIOController
 */

#pragma once

namespace GPIO
{
    /**
     * @brief Mode that pin actually working in 
     * 
     */
    enum PinMode
    {
        OUTPUT = 0,
        INPUT = 1,
        INPUT_PULLUP = 2
    };


    /**
     * @brief Type of pin
     * 
     */
    enum PinType
    {
        DIGITAL = 0,
        ANALOG = 1
    };
}

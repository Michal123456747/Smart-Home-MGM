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
        OUTPUT_ = 0,
        INPUT_ = 1,
        INPUT_PULLUP_ = 2
    };


    /**
     * @brief Type of pin
     * 
     */
    enum PinType
    {
        DIGITAL_ = 0,
        ANALOG_ = 1
    };
}

#include <gmock/gmock.h>
#include "GPIO/GPIOArduinoController.hpp"

TEST(GPIOControllerArduinoFr_ReservePin, ReserveSamePinTwice)
{
    GPIOManage::GPIOControllerArduinoFr test;

    EXPECT_TRUE(test.ReservePin(2, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));
    EXPECT_FALSE(test.ReservePin(2, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));

    EXPECT_TRUE(test.ReservePin(3, GPIOManage::ANALOG_, GPIOManage::INPUT_));
    EXPECT_TRUE(test.ReservePin(4, GPIOManage::ANALOG_, GPIOManage::OUTPUT_));
    EXPECT_TRUE(test.ReservePin(1, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));

    EXPECT_FALSE(test.ReservePin(3, GPIOManage::DIGITAL_, GPIOManage::INPUT_));
    EXPECT_FALSE(test.ReservePin(1, GPIOManage::ANALOG_, GPIOManage::OUTPUT_));
    EXPECT_FALSE(test.ReservePin(2, GPIOManage::ANALOG_, GPIOManage::INPUT_PULLUP_));
}

TEST(GPIOControllerArduinoFr_ReadFromPin, PinNotFound)
{
    GPIOManage::GPIOControllerArduinoFr test;

    EXPECT_EQ(0, test.ReadFromPin(1));

    EXPECT_TRUE(test.ReservePin(1, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));
    EXPECT_TRUE(test.ReservePin(2, GPIOManage::ANALOG_, GPIOManage::OUTPUT_));

    EXPECT_TRUE(test.WriteToPin(1, true));

    uint uint_ = 69;
    EXPECT_TRUE(test.WriteToPin(2, uint_));

    EXPECT_EQ(true, test.ReadFromPin(1));
    EXPECT_EQ(69, test.ReadFromPin(2));
}

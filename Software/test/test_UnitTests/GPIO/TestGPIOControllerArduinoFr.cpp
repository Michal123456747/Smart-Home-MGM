#include <gmock/gmock.h>
#include "GPIO/GPIOControllerArduinoFr.hpp"

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

TEST(GPIOControllerArduinoFr_WriteToPin, PinNotFound)
{
    GPIOManage::GPIOControllerArduinoFr test;
    uint val = 64;

    EXPECT_FALSE(test.WriteToPin(1, true));
    EXPECT_FALSE(test.WriteToPin(2, false));
    EXPECT_FALSE(test.WriteToPin(1, val));
    EXPECT_FALSE(test.WriteToPin(3, val));

    EXPECT_TRUE(test.ReservePin(1, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));
    EXPECT_TRUE(test.ReservePin(2, GPIOManage::ANALOG_, GPIOManage::OUTPUT_));

    EXPECT_FALSE(test.WriteToPin(1, val));
    EXPECT_FALSE(test.WriteToPin(2, true));

    EXPECT_TRUE(test.WriteToPin(1, false));
    EXPECT_TRUE(test.WriteToPin(1, false));
    EXPECT_TRUE(test.WriteToPin(1, true));

    EXPECT_TRUE(test.WriteToPin(2, val));
    val++;
    EXPECT_TRUE(test.WriteToPin(2, val));

}

TEST(GPIOControllerArduinoFr_WriteToPin, WrongType)
{
    GPIOManage::GPIOControllerArduinoFr test;
    uint val = 64;

    EXPECT_TRUE(test.ReservePin(1, GPIOManage::ANALOG_, GPIOManage::OUTPUT_));
    EXPECT_TRUE(test.ReservePin(2, GPIOManage::DIGITAL_, GPIOManage::INPUT_));
    EXPECT_TRUE(test.ReservePin(3, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));
    EXPECT_TRUE(test.ReservePin(4, GPIOManage::ANALOG_, GPIOManage::INPUT_));

    EXPECT_FALSE(test.WriteToPin(1, true));
    EXPECT_FALSE(test.WriteToPin(2, val));
    val++;
    EXPECT_FALSE(test.WriteToPin(3, val));
    EXPECT_FALSE(test.WriteToPin(4, false));
    EXPECT_FALSE(test.WriteToPin(5, val));

}

TEST(GPIOControllerArduinoFr_ReadFromPin, PinNotFound)
{
    GPIOManage::GPIOControllerArduinoFr test;

    EXPECT_EQ(0, test.ReadFromPin(1));

    EXPECT_TRUE(test.ReservePin(1, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));
    EXPECT_TRUE(test.ReservePin(2, GPIOManage::ANALOG_, GPIOManage::OUTPUT_));

    EXPECT_TRUE(test.WriteToPin(1, true));

    uint val = 69;
    EXPECT_TRUE(test.WriteToPin(2, val));

    EXPECT_EQ(true, test.ReadFromPin(1));
    EXPECT_EQ(69, test.ReadFromPin(2));
}


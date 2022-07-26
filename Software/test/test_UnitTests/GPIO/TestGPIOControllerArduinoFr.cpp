#include <gmock/gmock.h>
#include "GPIO/GPIOArduinoController.hpp"

TEST(GPIOControllerArduinoFr_ReservePin, ReserveSamePinTwice)
{
    GPIOManage::GPIOControllerArduinoFr foo;

    EXPECT_TRUE(foo.ReservePin(2, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));
    EXPECT_FALSE(foo.ReservePin(2, GPIOManage::DIGITAL_, GPIOManage::OUTPUT_));

}

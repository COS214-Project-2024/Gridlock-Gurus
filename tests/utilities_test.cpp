#include <gtest/gtest.h>
#include "../headers/Power.h"
#include "../headers/Water.h"
#include "../headers/Sanitation.h"
#include "../headers/Utilities.h"

class UtilitiesTest : public ::testing::Test {
protected:
    Power* power = new Power();
    Water* water = new Water();
    Sanitation* sanitation = new Sanitation();
};

TEST_F(UtilitiesTest, PowerShed) {
    testing::internal::CaptureStdout();
    power->shed();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Power utility is now shedding to conserve resources.\n");

    testing::internal::CaptureStdout();
    power->shed();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Power utility is already shedding.\n");
}

TEST_F(UtilitiesTest, PowerRepair) {
    power->breakUtility();
    testing::internal::CaptureStdout();
    power->repair();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Power utility repaired. Cost of repair: 100 units.\n");

    testing::internal::CaptureStdout();
    power->repair();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Power utility is operational and does not need repairs.\n");
}

TEST_F(UtilitiesTest, WaterShed) {
    testing::internal::CaptureStdout();
    water->shed();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Water utility is now shedding to reduce usage.\n");

    testing::internal::CaptureStdout();
    water->shed();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Water utility is already shedding.\n");
}

TEST_F(UtilitiesTest, WaterRepair) {
    water->breakUtility();
    testing::internal::CaptureStdout();
    water->repair();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Water utility repaired. Cost of repair: 50 units.\n");

    testing::internal::CaptureStdout();
    water->repair();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Water utility is operational and does not need repairs.\n");
}

TEST_F(UtilitiesTest, SanitationShed) {
    testing::internal::CaptureStdout();
    sanitation->shed();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sanitation system is now shedding to conserve water resources.\n");

    testing::internal::CaptureStdout();
    sanitation->shed();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sanitation system is already shedding.\n");
}

TEST_F(UtilitiesTest, SanitationRepair) {
    sanitation->breakUtility();
    testing::internal::CaptureStdout();
    sanitation->repair();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sanitation system repaired. Cost of repair: 30 units.\n");

    testing::internal::CaptureStdout();
    sanitation->repair();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sanitation system is operational and does not need repairs.\n");
}

TEST_F(UtilitiesTest, CheckCapacity) {
    testing::internal::CaptureStdout();
    power->checkCapacity();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Power capacity is at maximum output: 500 MW.\n");

    testing::internal::CaptureStdout();
    water->checkCapacity();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Water supply capacity: 300 liters per minute.\n");

    testing::internal::CaptureStdout();
    sanitation->checkCapacity();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sanitation system processing capacity: 200 liters per minute.\n");
<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes

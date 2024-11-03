#include <gtest/gtest.h>
#include "../headers/TransportDepartment.h"
#include "../headers/Vehicle.h"
#include "../headers/VehicleType.h"
#include <memory>

class transport_system_test : public ::testing::Test {
    protected:
        TransportDepartment* department;
        Vehicle* v1;
        Vehicle* v2;

        void SetUp() override {
            department = new TransportDepartment();
            v1 = new Vehicle(VehicleType::Taxi,4,*department);
            v2 = new Vehicle(VehicleType::Train,15,*department);
        }

        void TearDown() override {
            delete department;
        }
};

// Test Constructor
TEST_F(transport_system_test, transport_test) {
    department->addVehicle(*v1);
    EXPECT_EQ(department->getSize(),1);
    department->addVehicle(*v2);
    EXPECT_EQ(department->getSize(),2);
    
    EXPECT_EQ(v1->getType(),VehicleType::Taxi);
    EXPECT_EQ(v2->getType(),VehicleType::Train);
    EXPECT_EQ(v1->getState(),VehicleState::Functional);
    EXPECT_EQ(v2->getState(),VehicleState::Functional);

    EXPECT_EQ(v1->getCapacity(),4);
    EXPECT_EQ(v2->getCapacity(),15);
    EXPECT_EQ(v1->getCurrentPassengers(),0);
    EXPECT_EQ(v2->getCurrentPassengers(),0);
    EXPECT_EQ(v1->getUsage(),0);
    EXPECT_EQ(v2->getUsage(),0);

    //EXPECT_EQ(department->getAvailableVehicle(VehicleType::Taxi,*v1);
    //EXPECT_EQ(department->getAvailableVehicle(VehicleType::Train,*v2);
    v1->collect(2);
    v2->collect(2);

    EXPECT_EQ(v1->getUsage(),1);
    EXPECT_EQ(v2->getUsage(),1);
    EXPECT_EQ(v1->getState(),VehicleState::Functional);
    EXPECT_EQ(v2->getState(),VehicleState::Functional);

    v1->collect(5);
    v2->collect(16);
    EXPECT_EQ(v1->getUsage(),0);
    EXPECT_EQ(v2->getUsage(),0);
    EXPECT_EQ(v1->getState(),VehicleState::Functional);
    EXPECT_EQ(v2->getState(),VehicleState::Functional);
}



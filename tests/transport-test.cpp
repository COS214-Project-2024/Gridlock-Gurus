#include "gtest/gtest.h"
#include "../headers/TransportDepartment.h"
#include "../headers/Vehicle.h"
#include "../headers/Functional.h"
#include "../headers/Broken.h"
#include "../headers/Taxi.h"
#include "../headers/Truck.h"
#include "../headers/Train.h"
#include "../headers/Citizen.h"
#include <memory>

class TransportDepartmentTest : public ::testing::Test {
protected:
    TransportDepartment* transportDept;
    Taxi* taxi;
    Truck* truck;
    Train* train;
    std::shared_ptr<TaxAuthority> taxAuth;
    Citizen* citizen;

    void SetUp() override {
        transportDept = new TransportDepartment();
        taxi = new Taxi(4, transportDept);
        truck = new Truck(2, transportDept);
        train = new Train(10, transportDept);
        taxAuth = std::make_shared<TaxAuthority>();
        citizen = new Citizen(0, CitizenType::Citizen,100, 300, taxAuth);
    }

    void TearDown() override {
        delete taxi;
        delete truck;
        delete train;
        delete citizen;
        delete transportDept;
    }
};

TEST_F(TransportDepartmentTest, AddAndGetAvailableTaxi) {
    transportDept->addVehicle(taxi);
    EXPECT_NO_THROW(transportDept->getAvailableVehicle("Taxi"));
}

TEST_F(TransportDepartmentTest, GetAvailableTaxi) {
    transportDept->addVehicle(taxi);
    Vehicle* available = transportDept->getAvailableVehicle("Taxi");
    EXPECT_EQ(available->getType(), "Taxi");
}

TEST_F(TransportDepartmentTest, GetAvailableTaxiWhenBroken) {
    transportDept->addVehicle(taxi);
    taxi->breakDown(); // Set taxi to broken
    EXPECT_THROW(transportDept->getAvailableVehicle("Taxi"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, AddAndGetAvailableTruck) {
    transportDept->addVehicle(truck);
    EXPECT_NO_THROW(transportDept->getAvailableVehicle("Truck"));
}

TEST_F(TransportDepartmentTest, GetAvailableTruck) {
    transportDept->addVehicle(truck);
    Vehicle* available = transportDept->getAvailableVehicle("Truck");
    EXPECT_EQ(available->getType(), "Truck");
}

TEST_F(TransportDepartmentTest, GetAvailableTruckWhenBroken) {
    transportDept->addVehicle(truck);
    truck->breakDown();
    EXPECT_THROW(transportDept->getAvailableVehicle("Truck"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, AddAndGetAvailableTrain) {
    transportDept->addVehicle(train);
    EXPECT_NO_THROW(transportDept->getAvailableVehicle("Train"));
}

TEST_F(TransportDepartmentTest, GetAvailableTrain) {
    transportDept->addVehicle(train);
    Vehicle* available = transportDept->getAvailableVehicle("Train");
    EXPECT_EQ(available->getType(), "Train");
}

TEST_F(TransportDepartmentTest, GetAvailableTrainWhenBroken) {
    transportDept->addVehicle(train);
    train->breakDown();
    EXPECT_THROW(transportDept->getAvailableVehicle("Train"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, RepairTaxi) {
    transportDept->addVehicle(taxi);
    taxi->breakDown();
    EXPECT_NE(dynamic_cast<Broken*>(taxi->getState()), nullptr);
    transportDept->repairVehicles(taxi);
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, ManageFunctionalityWithBrokenVehicles) {
    transportDept->addVehicle(taxi);
    transportDept->addVehicle(truck);
    transportDept->addVehicle(train);

    taxi->breakDown();
    EXPECT_NE(dynamic_cast<Broken*>(taxi->getState()), nullptr);

    truck->incrementUsage();
    truck->incrementUsage();
    truck->incrementUsage();

    transportDept->manage();
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, CitizenRequestAvailableTaxi) {
    transportDept->addVehicle(taxi);
    EXPECT_NO_THROW(citizen->callTransport(*transportDept, "Taxi"));
}

TEST_F(TransportDepartmentTest, CitizenRequestBrokenTaxi) {
    transportDept->addVehicle(taxi);
    taxi->breakDown();
    EXPECT_NO_THROW(citizen->callTransport(*transportDept, "Taxi"));
}

TEST_F(TransportDepartmentTest, CitizenRequestNonExistentVehicle) {
    EXPECT_NO_THROW(citizen->callTransport(*transportDept, "NonExistentVehicle"));
}

TEST_F(TransportDepartmentTest, ManageVehiclesWithAllBroken) {
    taxi->breakDown();
    truck->breakDown();
    train->breakDown();

    transportDept->addVehicle(taxi);
    transportDept->addVehicle(truck);
    transportDept->addVehicle(train);

    // Manage function should attempt repairs
    EXPECT_NO_THROW(transportDept->manage());
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr); // Assuming manage can repair if conditions met
    EXPECT_NE(dynamic_cast<Functional*>(truck->getState()), nullptr);
    EXPECT_NE(dynamic_cast<Functional*>(train->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, ManagePartialFunctionalVehicles) {
    taxi->breakDown();
    truck->incrementUsage();
    transportDept->addVehicle(taxi);
    transportDept->addVehicle(truck);

    EXPECT_NO_THROW(transportDept->manage());
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, RequestAfterAllBroken) {
    transportDept->addVehicle(taxi);
    transportDept->addVehicle(truck);
    transportDept->addVehicle(train);

    taxi->breakDown();
    truck->breakDown();
    train->breakDown();

    EXPECT_THROW(citizen->callTransport(*transportDept, "Taxi"), std::runtime_error);
}


TEST_F(TransportDepartmentTest, RepairAllVehicles) {
    taxi->breakDown();
    truck->breakDown();
    train->breakDown();

    transportDept->addVehicle(taxi);
    transportDept->addVehicle(truck);
    transportDept->addVehicle(train);

    transportDept->manage(); // Assuming it tries to repair as needed
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
    EXPECT_NE(dynamic_cast<Functional*>(truck->getState()), nullptr);
    EXPECT_NE(dynamic_cast<Functional*>(train->getState()), nullptr);
}

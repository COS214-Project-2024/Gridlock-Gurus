#include <gtest/gtest.h>
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
    std::unique_ptr<TransportDepartment> transportDept;
    std::unique_ptr<Taxi> taxi;
    std::unique_ptr<Truck> truck;
    std::unique_ptr<Train> train;
    std::shared_ptr<TaxAuthority> taxAuth;
    std::unique_ptr<Citizen> citizen;

    void SetUp() override {
        transportDept = std::make_unique<TransportDepartment>();
        taxi = std::make_unique<Taxi>(4, transportDept.get());
        truck = std::make_unique<Truck>(2, transportDept.get());
        train = std::make_unique<Train>(10, transportDept.get());
        taxAuth = std::make_shared<TaxAuthority>();
        citizen = std::make_unique<Citizen>(0, CitizenType::Citizen, 100, 300, taxAuth);
    }

    void TearDown() override {

    }
};

TEST_F(TransportDepartmentTest, AddAndGetAvailableTaxi) {
    transportDept->addVehicle(taxi.get());
    EXPECT_NO_THROW(transportDept->getAvailableVehicle("Taxi"));
}

TEST_F(TransportDepartmentTest, GetAvailableTaxi) {
    transportDept->addVehicle(taxi.get());
    Vehicle* available = transportDept->getAvailableVehicle("Taxi");
    EXPECT_EQ(available->getType(), "Taxi");
}

TEST_F(TransportDepartmentTest, GetAvailableTaxiWhenBroken) {
    transportDept->addVehicle(taxi.get());
    taxi->breakDown(); // Set taxi to broken
    EXPECT_THROW(transportDept->getAvailableVehicle("Taxi"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, AddAndGetAvailableTruck) {
    transportDept->addVehicle(truck.get());
    EXPECT_NO_THROW(transportDept->getAvailableVehicle("Truck"));
}

TEST_F(TransportDepartmentTest, GetAvailableTruck) {
    transportDept->addVehicle(truck.get());
    Vehicle* available = transportDept->getAvailableVehicle("Truck");
    EXPECT_EQ(available->getType(), "Truck");
}

TEST_F(TransportDepartmentTest, GetAvailableTruckWhenBroken) {
    transportDept->addVehicle(truck.get());
    truck->breakDown();
    EXPECT_THROW(citizen->callTransport(*transportDept, "Truck"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, AddAndGetAvailableTrain) {
    transportDept->addVehicle(train.get());
    EXPECT_NO_THROW(transportDept->getAvailableVehicle("Train"));
}

TEST_F(TransportDepartmentTest, GetAvailableTrain) {
    transportDept->addVehicle(train.get());
    Vehicle* available = transportDept->getAvailableVehicle("Train");
    EXPECT_EQ(available->getType(), "Train");
}

TEST_F(TransportDepartmentTest, GetAvailableTrainWhenBroken) {
    transportDept->addVehicle(train.get());
    train->breakDown();
    EXPECT_THROW(transportDept->getAvailableVehicle("Train"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, RepairTaxi) {
    transportDept->addVehicle(taxi.get());
    taxi->breakDown();
    EXPECT_NE(dynamic_cast<Broken*>(taxi->getState()), nullptr);
    transportDept->repairVehicles(taxi.get());
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, ManageFunctionalityWithBrokenVehicles) {
    transportDept->addVehicle(taxi.get());
    transportDept->addVehicle(truck.get());
    transportDept->addVehicle(train.get());

    taxi->breakDown();
    EXPECT_NE(dynamic_cast<Broken*>(taxi->getState()), nullptr);

    truck->incrementUsage();
    truck->incrementUsage();
    truck->incrementUsage();

    transportDept->manage();
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, CitizenRequestAvailableTaxi) {
    transportDept->addVehicle(taxi.get());
    EXPECT_NO_THROW(citizen->callTransport(*transportDept, "Taxi"));
}

TEST_F(TransportDepartmentTest, CitizenRequestBrokenTaxi) {
    transportDept->addVehicle(taxi.get());
    taxi->breakDown();
    EXPECT_THROW(citizen->callTransport(*transportDept, "Taxi"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, CitizenRequestNonExistentVehicle) {
    EXPECT_THROW(citizen->callTransport(*transportDept, "NonExistentVehicle"), std::runtime_error);
}

TEST_F(TransportDepartmentTest, ManageVehiclesWithAllBroken) {
    taxi->breakDown();
    truck->breakDown();
    train->breakDown();

    transportDept->addVehicle(taxi.get());
    transportDept->addVehicle(truck.get());
    transportDept->addVehicle(train.get());

    EXPECT_NO_THROW(transportDept->manage());
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
    EXPECT_NE(dynamic_cast<Functional*>(truck->getState()), nullptr);
    EXPECT_NE(dynamic_cast<Functional*>(train->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, ManagePartialFunctionalVehicles) {
    taxi->breakDown();
    truck->incrementUsage();
    transportDept->addVehicle(taxi.get());
    transportDept->addVehicle(truck.get());

    EXPECT_NO_THROW(transportDept->manage());
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
}

TEST_F(TransportDepartmentTest, RequestAfterAllBroken) {
    transportDept->addVehicle(taxi.get());
    transportDept->addVehicle(truck.get());
    transportDept->addVehicle(train.get());

    taxi->breakDown();
    truck->breakDown();
    train->breakDown();

    EXPECT_THROW(citizen->callTransport(*transportDept, "Taxi"), std::runtime_error);
}


TEST_F(TransportDepartmentTest, RepairAllVehicles) {
    taxi->breakDown();
    truck->breakDown();
    train->breakDown();

    transportDept->addVehicle(taxi.get());
    transportDept->addVehicle(truck.get());
    transportDept->addVehicle(train.get());

    transportDept->manage();
    EXPECT_NE(dynamic_cast<Functional*>(taxi->getState()), nullptr);
    EXPECT_NE(dynamic_cast<Functional*>(truck->getState()), nullptr);
    EXPECT_NE(dynamic_cast<Functional*>(train->getState()), nullptr);
}

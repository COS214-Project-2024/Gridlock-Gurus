#include <gtest/gtest.h>
#include "../headers/Citizen.h"
#include "../headers/CitizenType.h"
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/City.h"
#include "../headers/Government.h"
#include "../headers/BuildingType.h"


#include <memory>

class government_test : public ::testing::Test {
    protected:
        City* city;

        void SetUp() override {
            city = new City();
        }
        
        void TearDown() override {
            delete city;
        }
};

// Test Constructor
TEST_F(government_test, construction_test) {
    EXPECT_EQ(city->getState(),CityState::Happy);
    EXPECT_EQ(city->checkCityFunds(),20000);
    EXPECT_EQ(city->getCitizenCount(),0);
    EXPECT_EQ(city->getWorkerCount(),0);
    EXPECT_EQ(city->getBuildingCount(),0);

    city->startTaxCycle();
    EXPECT_EQ(city->checkCityFunds(),20000);

    EXPECT_EQ(city->getCitizenHappiness(),0);
    city->setCitizenHappiness(100);
    EXPECT_EQ(city->getCitizenHappiness(),100);
    city->calculateHappiness();
    EXPECT_EQ(city->getCitizenHappiness(),0);
    EXPECT_EQ(city->getState(),CityState::Upset);

    city->removeLastBuilding();

}

TEST_F(government_test, tax_test) {
    EXPECT_EQ(city->checkCityFunds(),20000);
    city->startTaxCycle();
    EXPECT_EQ(city->checkCityFunds(),20000);
    city->addBuilding(BuildingType::BrickFactory);
    city->startTaxCycle();
    EXPECT_GT(city->checkCityFunds(),20000);
    EXPECT_GT(city->getCitizenCount(),0);
    EXPECT_GT(city->getWorkerCount(),0);
    EXPECT_EQ(city->getBuildingCount(),1);
}

TEST_F(government_test, utility_test) {
    city->checkUtilityUsage();
    city->upgradeUtilities();
    city->repairUtilities();
    std::string s = "";
    city->getUtilityStats(s);
}

TEST_F(government_test, transport_test) {
}

#include <gtest/gtest.h>
#include "../headers/Citizen.h"
#include "../headers/CitizenType.h"
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/City.h"
#include "../headers/Government.h"

#include <memory>

class government_test : public ::testing::Test {
    protected:
        City* city;

        void SetUp() override {
            city = new City();
        }
        
        void TearDown() override {
        }
};

// Test Constructor
TEST_F(government_test, construction_test) {
    EXPECT_EQ(city->getState(),CityState::Happy);
    EXPECT_EQ(city->checkFunds(),20000);

    city->startTaxCycle();
    EXPECT_EQ(city->checkFunds(),20000);

    EXPECT_EQ(city->getCitizenHappiness(),0);
    EXPECT_EQ(city->setCitizenHappiness(),100);
    EXPECT_EQ(city->getCitizenHappiness(),100);
    city->calculateCitizenHappiness();
    EXPECT_EQ(city->getCitizenHappiness(),0);
    EXPECT_EQ(city->getState(),CityState::Upset);

    city->removeLastBuilding();

}

/*TEST_F(citizen_test, citizen_tax_test) {
    BrickFactory* workPtr = dynamic_cast<BrickFactory*>(work);

    c->payTaxes(100);
    EXPECT_EQ(c->getFunds(),300);
    workPtr->employ(*c);
    EXPECT_EQ(c->getEmploymentStatus(),true);
    EXPECT_EQ(c->getType(),CitizenType::Worker);
    c->payTaxes(100);
    EXPECT_EQ(c->getFunds(),200);
    c->workDay();
    EXPECT_EQ(c->getFunds(),300);

}

TEST_F(citizen_test, citizen_home_test) {
    Residential* homePtr = dynamic_cast<Residential*>(home);
    EXPECT_EQ(c->hasHome(),false);
    EXPECT_EQ(homePtr->isFull(),false);
    homePtr->addTenant(*c);
    EXPECT_EQ(c->hasHome(),true);

}

TEST_F(citizen_test, citizen_fire_test) {
    BrickFactory* workPtr = dynamic_cast<BrickFactory*>(work);
    workPtr->employ(*c);
    EXPECT_EQ(c->getEmploymentStatus(),true);
    EXPECT_EQ(c->getType(),CitizenType::Worker);
    workPtr->fire(*c);
    EXPECT_EQ(c->getEmploymentStatus(),false);
    EXPECT_EQ(c->getType(),CitizenType::Citizen);

}

TEST_F(citizen_test, citizen_Retire_test) {
    BrickFactory* workPtr = dynamic_cast<BrickFactory*>(work);
    workPtr->employ(*c);
    EXPECT_EQ(c->getEmploymentStatus(),true);
    EXPECT_EQ(c->getType(),CitizenType::Worker);
    workPtr->retire(*c);
    EXPECT_EQ(c->getEmploymentStatus(),false);
    EXPECT_EQ(c->getType(),CitizenType::Retired);
    EXPECT_EQ(c->hasHome(),false);
}*/

#include <gtest/gtest.h>
#include "../headers/Citizen.h"
#include "../headers/CitizenType.h"
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/Factory.h"
#include "../headers/BrickFactory.h"
#include "../headers/FactoryFactory.h"
#include "../headers/BuildingType.h"
#include "../headers/Residential.h"
#include "../headers/ResidentialFactory.h"

#include <memory>

class government_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth;
        
        void SetUp() override {
            taxAuth = std::make_shared<TaxAuthority>();
        }
        
        void TearDown() override {
        }
};

// Test Constructor
/*TEST_F(government_test, construction_test) {
    EXPECT_EQ(c->getId(),0);
    EXPECT_EQ(c->getType(),CitizenType::Citizen);
    EXPECT_EQ(c->getSatisfactionLevel(),100);
    EXPECT_EQ(c->getFunds(),300);
    EXPECT_EQ(c->hasHome(),false);
    EXPECT_EQ(c->getEmploymentStatus(),false);
    EXPECT_EQ(c->isInVehicle(),false);

}

TEST_F(citizen_test, citizen_tax_test) {
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

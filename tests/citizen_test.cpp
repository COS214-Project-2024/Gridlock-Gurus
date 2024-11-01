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

class citizen_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth;
        Citizen* c;
        Building* work;
        Building* home;
        FactoryFactory* factory;
        ResidentialFactory* homeFactory;

        void SetUp() override {
            taxAuth = std::make_shared<TaxAuthority>();
            factory = new FactoryFactory(taxAuth);
            homeFactory = new ResidentialFactory(taxAuth);
            c = new Citizen(0,CitizenType::Citizen,100,300,taxAuth);
            work = factory->createBuilding(BuildingType::BrickFactory,*c);

            home = homeFactory->createBuilding(BuildingType::House,*c);     
        }
        
        void TearDown() override {
            delete factory;
            delete homeFactory;
            delete c;

        }
};

// Test Constructor
TEST_F(citizen_test, citizen_construction_test) {
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
}

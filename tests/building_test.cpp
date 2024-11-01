#include <gtest/gtest.h>
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/BuildingFactory.h"
#include "../headers/SteelFactory.h"
#include "../headers/Citizen.h"
#include "../headers/Resources.h"
#include "../headers/Commercial.h"
#include "../headers/CommercialFactory.h"
#include "../headers/BuildingType.h"
#include "../headers/Citizen.h"
#include "../headers/CitizenType.h"
#include "../headers/BrickFactory.h"
#include "../headers/WoodFactory.h"
#include "../headers/SteelFactory.h"
#include "../headers/FactoryFactory.h"
#include "../headers/Residential.h"
#include "../headers/ResidentialFactory.h"
#include "../headers/Landmark.h"
#include "../headers/LandmarkFactory.h"
#include "../headers/Service.h"
#include "../headers/EducationService.h"
#include "../headers/HealthService.h"
#include "../headers/PoliceService.h"
#include "../headers/ServiceFactory.h"

#include <string>
#include <iostream>
#include <memory>

class building_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth;

        FactoryFactory* factory_factory;
        ResidentialFactory* homeFactory;
        ServiceFactory* service_factory;
        LandmarkFactory* landmark_factory;
        BuildingFactory* building_factory;

        Building* b1;
        Building* brick_factory;
        Building* steel_factory;
        Building* wood_factory;

        Building* home;

        Building* school;
        Building* police;
        Building* health;

        Building* landmark;

        Citizen* citizen;

        void SetUp() override {
            taxAuth = std::make_shared<TaxAuthority>();
            citizen = new Citizen(0,CitizenType::Citizen,100,10000,taxAuth);

            building_factory = new CommercialFactory(taxAuth);
            service_factory = new ServiceFactory(taxAuth);
            landmark_factory = new LandmarkFactory(taxAuth);
            factory_factory = new FactoryFactory(taxAuth);
            homeFactory = new ResidentialFactory(taxAuth);

            brick_factory = factory_factory->createBuilding(BuildingType::BrickFactory,*citizen);
            steel_factory = factory_factory->createBuilding(BuildingType::SteelFactory,*citizen);
            wood_factory = factory_factory->createBuilding(BuildingType::WoodFactory,*citizen);

            school = service_factory->createBuilding(BuildingType::School,*citizen);
            police = service_factory->createBuilding(BuildingType::PoliceStation,*citizen);
            health = service_factory->createBuilding(BuildingType::Hospital,*citizen);

            landmark = landmark_factory->createBuilding(BuildingType::Statue,*citizen);
            home = homeFactory->createBuilding(BuildingType::House,*citizen);     

            b1 = building_factory->createBuilding(BuildingType::Bank, *citizen);
        }

        void TearDown() override {
            // Buildings are deleted in the building collection so do not need to be deleted manually
            delete building_factory;
            delete service_factory;
            delete landmark_factory;
            delete factory_factory;
            delete homeFactory;

            delete citizen;
            
        }
};

// Test Constructor
TEST_F(building_test, commercial_test_construction) {

    Commercial* commercialPtr = dynamic_cast<Commercial*>(b1);
    if (commercialPtr) {
        EXPECT_EQ(commercialPtr->getMaxEmployees(), 30);
        EXPECT_EQ(commercialPtr->getProductionRate(), 6);
        EXPECT_EQ(commercialPtr->getNumberOfEmployees(), 0);
    } else {
        FAIL() << "building b1 is not a Commercial type";
    }

    EXPECT_EQ(b1->getCost(),200);
    EXPECT_EQ(b1->getLocation(),"Business district");
    EXPECT_EQ(b1->getSize(),1000);
    EXPECT_EQ(b1->getName(),BuildingType::Bank);

    // Brick
    BrickFactory* brickPtr = dynamic_cast<BrickFactory*>(brick_factory);
    if (brickPtr) {
        EXPECT_EQ(brickPtr->produceResource(), 100);
        EXPECT_EQ(brickPtr->pay(), 100);
        EXPECT_EQ(brickPtr->getNumberOfEmployees(), 0);
    } else {
        FAIL() << "building brick_factory is not a BrickFactory type";
    }

    EXPECT_EQ(brick_factory->getCost(),500);
    EXPECT_EQ(brick_factory->getLocation(),"Factory district");
    EXPECT_EQ(brick_factory->getSize(),1000);
    EXPECT_EQ(brick_factory->getName(),BuildingType::BrickFactory);
    
    //Steel
    SteelFactory* steelPtr = dynamic_cast<SteelFactory*>(steel_factory);
    if (steelPtr) {
        EXPECT_EQ(steelPtr->produceResource(), 100);
        EXPECT_EQ(steelPtr->pay(), 163);
        EXPECT_EQ(steelPtr->getNumberOfEmployees(), 0);
    } else {
        FAIL() << "building steel_factory is not a SteelFactory type";
    }

    EXPECT_EQ(steel_factory->getCost(),1000);
    EXPECT_EQ(steel_factory->getLocation(),"Factory district");
    EXPECT_EQ(steel_factory->getSize(),1000);
    EXPECT_EQ(steel_factory->getName(),BuildingType::SteelFactory);

    //wood
    WoodFactory* woodPtr = dynamic_cast<WoodFactory*>(wood_factory);
    if (woodPtr) {
        EXPECT_EQ(woodPtr->produceResource(), 100);
        EXPECT_EQ(woodPtr->pay(), 90);
        EXPECT_EQ(woodPtr->getNumberOfEmployees(), 0);
    } else {
        FAIL() << "building wood_factory is not a WoodFactory type";
    }

    EXPECT_EQ(wood_factory->getCost(),100);
    EXPECT_EQ(wood_factory->getLocation(),"Factory district");
    EXPECT_EQ(wood_factory->getSize(),1000);
    EXPECT_EQ(wood_factory->getName(),BuildingType::WoodFactory);
    
    //police
    PoliceService* PolicePtr = dynamic_cast<PoliceService*>(police);
    if (PolicePtr) {
        EXPECT_EQ(PolicePtr->getMaxEmployees(), 30);
        EXPECT_EQ(PolicePtr->getId(), 0);
        EXPECT_EQ(PolicePtr->getNumberOfEmployees(), 0);
        EXPECT_EQ(PolicePtr->pay(), 3300);
    } else {
        FAIL() << "building police is not a PoliceService type";
    }

    EXPECT_EQ(police->getCost(),300);
    EXPECT_EQ(police->getLocation(),"City Center");
    EXPECT_EQ(police->getSize(),300);
    EXPECT_EQ(police->getName(),BuildingType::PoliceStation);
    
    //school
    EducationService* schoolPtr = dynamic_cast<EducationService*>(school);
    if (schoolPtr) {
        EXPECT_EQ(schoolPtr->getMaxEmployees(), 30);
        EXPECT_EQ(schoolPtr->getId(), 0);
        EXPECT_EQ(schoolPtr->getNumberOfEmployees(), 0);
        EXPECT_EQ(schoolPtr->pay(), 2200);
        EXPECT_EQ(schoolPtr->getPrestige(), 0);

    } else {
        FAIL() << "building school is not a EducationService type";
    }

    EXPECT_EQ(school->getCost(),200);
    EXPECT_EQ(school->getLocation(),"City Center");
    EXPECT_EQ(school->getSize(),1000);
    EXPECT_EQ(school->getName(),BuildingType::School);
    
    //health
    HealthService* healthPtr = dynamic_cast<HealthService*>(health);
    if (healthPtr) {
        EXPECT_EQ(healthPtr->getMaxEmployees(), 30);
        EXPECT_EQ(healthPtr->getId(), 0);
        EXPECT_EQ(healthPtr->getNumberOfEmployees(), 0);
        EXPECT_EQ(healthPtr->pay(), 2200);
        EXPECT_EQ(healthPtr->getResponseTime(), 10);

    } else {
        FAIL() << "building health is not a HealthService type";
    }


    EXPECT_EQ(health->getCost(),500);
    EXPECT_EQ(health->getLocation(),"City Center");
    EXPECT_EQ(health->getSize(),500);
    EXPECT_EQ(health->getName(),BuildingType::Hospital);
    
    //home
    Residential* homePtr = dynamic_cast<Residential*>(home);
    if (homePtr) {
        EXPECT_EQ(homePtr->isFull(), false);
        EXPECT_EQ(homePtr->getNumberOfTenants(), 0);
    } else {
        FAIL() << "building home is not a Residential type";
    }


    EXPECT_EQ(home->getCost(),2000);
    EXPECT_EQ(home->getLocation(),"Suburbs");
    EXPECT_EQ(home->getSize(),500);
    EXPECT_EQ(home->getName(),BuildingType::House);

    //landmark
    Landmark* landPtr = dynamic_cast<Landmark*>(landmark);
    if (landPtr) {
    } else {
        FAIL() << "building landmark is not a landmark type";
    }

    EXPECT_EQ(landmark->getCost(),1000);
    EXPECT_EQ(landmark->getLocation(),"City center");
    EXPECT_EQ(landmark->getSize(),2000);
    EXPECT_EQ(landmark->getName(),BuildingType::Statue);

    EXPECT_EQ(taxAuth->getSize(),9);
}

TEST(SimpleTest, AlwaysPass) {
    EXPECT_TRUE(true); // This test will always pass
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

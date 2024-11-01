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

        Building* residential;

        Building* education;
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

            education = service_factory->createBuilding(BuildingType::School,*citizen);
            police = service_factory->createBuilding(BuildingType::PoliceStation,*citizen);
            health = service_factory->createBuilding(BuildingType::Hospital,*citizen);

            landmark = landmark_factory->createBuilding(BuildingType::Statue,*citizen);
            residential = homeFactory->createBuilding(BuildingType::House,*citizen);     

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
    //EXPECT_EQ(taxAuth->getSize(),1);
}

TEST(SimpleTest, AlwaysPass) {
    EXPECT_TRUE(true); // This test will always pass
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

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

#include <string>
#include <iostream>
#include <memory>

class building_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth;
        BuildingFactory* factory;
        Building* b1;
        //Building* b2;
        //Building* b3;
        Citizen* citizen;

        void SetUp() override {
            taxAuth = std::make_shared<TaxAuthority>();
            citizen = new Citizen(0,CitizenType::Citizen,100,10000,taxAuth);
            factory = new CommercialFactory(taxAuth);
            b1 = factory->createBuilding(BuildingType::Bank, *citizen);
        }

        void TearDown() override {
            // Buildings are deleted in the building collection so do not need to be deleted manually
            //delete b1;
            delete factory;
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
    EXPECT_EQ(taxAuth->getSize(),1);
}

TEST(SimpleTest, AlwaysPass) {
    EXPECT_TRUE(true); // This test will always pass
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

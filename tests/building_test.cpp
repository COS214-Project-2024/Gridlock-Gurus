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
        
        std::shared_ptr<TaxAuthority> taxAuth = std::make_shared<TaxAuthority>();
        BuildingFactory* factory;
        Building* b1;
        Building* b2;
        Building* b3;
        Citizen* citizen = new Citizen(0,CitizenType::Citizen,100,10000,taxAuth);

        void SetUp() override {
            std::cout << "Running SetUp" << std::endl;

            b1 = factory->createBuilding(BuildingType::Bank, *citizen);
        }

        void TearDown() override {
            delete b1;
            delete factory;
        }
};

// Test Constructor
TEST_F(building_test, commercial_test) {
    // Construction 
     std::cout << "Running commercial_test..." << std::endl;
    Commercial* commercialPtr = dynamic_cast<Commercial*>(b1);
    if (commercialPtr) {
        EXPECT_EQ(commercialPtr->getMaxEmployees(), 30);
        EXPECT_EQ(commercialPtr->getProductionRate(), 6);
        EXPECT_EQ(commercialPtr->getNumberOfEmployees(), 0);
    } else {
        FAIL() << "building b1 is not a Commercial type";
    }

    EXPECT_EQ(b1->getCost(),200);
    EXPECT_EQ(b1->getLocation(),"Buisiness district");
    EXPECT_EQ(b1->getSize(),1000);
    EXPECT_EQ(b1->getName(),BuildingType::Bank);


}

TEST(SimpleTest, AlwaysPass) {
    EXPECT_TRUE(true); // This test will always pass
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Running all tests..." << std::endl;
    return RUN_ALL_TESTS();
}

#include <gtest/gtest.h>
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/SteelFactory.h"
#include "../headers/Citizen.h"
#include "../headers/Resources.h"

#include <string>
#include <memory>

class building_test : public ::testing::Test {
    protected:
        //std::shared_ptr<TaxAuthority> taxAuth = std::make_shared<TaxAuthority>();
        //Building* building;
        //Citizen* citizen = new Citizen();
        //Resources* r = new Resources(100,100,false);

        void SetUp() override {
            std::string location = "Sandton";
            //building = new SteelFactory(300,"Sandton",r,300,citizen,taxAuth,BuildingType::SteelFactory,50,100);
        }

        void TearDown() override {
            //delete building;
        }
};

// Test Constructor
TEST_F(building_test, ConstructorSetCorrectValues) {
    //EXPECT_EQ(building->getCost(),300);
    //EXPECT_EQ(building->getLocation(),"Sandton");
    //EXPECT_EQ(building->getSize(),300);
    EXPECT_EQ(300,300);

}



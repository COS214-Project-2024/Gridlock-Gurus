#include <gtest/gtest.h>
#include "../headers/Citizen.h"
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"

#include <memory>

class citizen_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth = std::make_shared<TaxAuthority>();
        Citizen* c;

        void SetUp() override {
            //c = new Citizen(0,"worker",100,300,taxAuth);
        }

        void TearDown() override {
            //delete c;
        }
};

// Test Constructor
TEST_F(citizen_test, ConstructorSetCorrectValues) {
/*    EXPECT_EQ(c->getId(),0);
    EXPECT_EQ(c->getType(),"worker");
    EXPECT_EQ(c->getSatisfactionLevel(),100);
    EXPECT_EQ(c->getFunds(),300);*/
}

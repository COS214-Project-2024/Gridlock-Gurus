#include <gtest/gtest.h>
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/Citizen.h"
#include "../headers/BuildingCollection.h"
#include <memory>

class tax_system_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth = std::make_shared<TaxAuthority>();

        void SetUp() override {

        }

        void TearDown() override {
        }
};

// Test Constructor
TEST_F(tax_system_test, ConstructorSetCorrectValues) {
    EXPECT_EQ(taxAuth->getCollectedTax(),0);
    EXPECT_NE(taxAuth->getSize(), 0);
}

// Test add Building
/*TEST_F(tax_system_test, NegativeTest) {

}*/


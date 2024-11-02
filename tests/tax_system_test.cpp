#include <gtest/gtest.h>
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/Citizen.h"
#include "../headers/BuildingCollection.h"
#include "../headers/FlatTaxStrategy.h"
#include "../headers/ProgressiveTaxStrategy.h"
#include "../headers/FactoryFactory.h"
#include "../headers/CitizenFactory.h"
#include "../headers/CitizenType.h"
#include "../headers/BrickFactory.h"
#include <memory>

class tax_system_test : public ::testing::Test {
    protected:
        std::shared_ptr<TaxAuthority> taxAuth;
        CitizenFactory* citizen_factory;
        FactoryFactory* factory_factory;
        Citizen* citizen1;
        Citizen* citizen2;

        Building* factory1;
        Building* factory2;

        void SetUp() override {
            taxAuth = std::make_shared<TaxAuthority>();
            citizen_factory = new CitizenFactory(taxAuth);
            factory_factory = new FactoryFactory(taxAuth);
        }

        void TearDown() override {
            delete factory_factory;
            delete citizen_factory;
            delete citizen1;
            delete citizen2;
        }
};

// Test Constructor
TEST_F(tax_system_test, ConstructorSetCorrectValues) {
    EXPECT_EQ(taxAuth->getCollectedTax(),0);
    EXPECT_EQ(taxAuth->getSize(), 0);
    EXPECT_EQ(taxAuth->getAmountOfCitizens(), 0);
    taxAuth->sendTax(3);
    EXPECT_EQ(taxAuth->getCollectedTax(),3);
    taxAuth->sendTax(5);
    EXPECT_EQ(taxAuth->getCollectedTax(),8);
    //EXPECT_EQ(taxAuth->calculateCitizenTax(100),30);
    //EXPECT_EQ(taxAuth->calculateBuildingTax(100),30);
   
    //EXPECT_EQ(taxAuth->calculateCitizenTax(100),60);
    //EXPECT_EQ(taxAuth->calculateBuildingTax(100),60);

    citizen2 = citizen_factory->createCitizen(CitizenType::Citizen,100,1000);
    citizen1 = citizen_factory->createCitizen(CitizenType::Worker,100,1000);

    EXPECT_EQ(taxAuth->getAmountOfCitizens(), 2);

    factory1 = factory_factory->createBuilding(BuildingType::BrickFactory,*citizen1);
    factory2 = factory_factory->createBuilding(BuildingType::BrickFactory,*citizen1);
    EXPECT_EQ(taxAuth->getSize(), 2);
    BrickFactory* fac1 = dynamic_cast<BrickFactory*>(factory1);
    //BrickFactory* fac2 = dynamic_cast<BrickFactory*>(factory2);


    fac1->employ(*citizen1);
    fac1->employ(*citizen2);
    taxAuth->collectTaxes();
    // 30 + 30 + 30 = 90 (0wns buildings)
    EXPECT_EQ(citizen1->getFunds(),910);
    EXPECT_EQ(citizen2->getFunds(),970);
    taxAuth->setStrategy(std::make_unique<ProgressiveTaxStrategy>());
    taxAuth->collectTaxes();
    //  300 + 300 + 546 = 90 (0wns buildings)
    EXPECT_EQ(citizen1->getFunds(),124);
    EXPECT_EQ(citizen2->getFunds(),388);


}



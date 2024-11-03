#include <gtest/gtest.h>
#include "../headers/Citizen.h"
#include "../headers/CitizenType.h"
#include "../headers/TaxAuthority.h"
#include "../headers/Building.h"
#include "../headers/City.h"
#include "../headers/Government.h"
#include "../headers/BuildingType.h"
#include "../headers/VehicleType.h"
#include "../headers/Command.h"
#include "../headers/BuildCommand.h"
#include "../headers/ChangeTaxStrategyCommand.h"
#include "../headers/CityReportCommand.h"
#include "../headers/IncreaseTransportCommand.h"
#include "../headers/RepairUtilitiesCommand.h"
#include "../headers/UpgradeUtilitiesCommand.h"


#include <iostream>
#include <string>

#include <memory>

class government_test : public ::testing::Test {
    protected:
        std::shared_ptr<City> city;
        BuildCommand* buildC;
        ChangeTaxStrategyCommand* strategyC;
        CityReportCommand* reportC;
        IncreaseTransportCommand* incTrC;
        RepairUtilitiesCommand* repairC;
        UpgradeUtilitiesCommand* upC;
        std::string city_report;

        void SetUp() override {
            this->city = std::make_shared<City>();
            buildC = new BuildCommand(city,BuildingType::BrickFactory);
            strategyC = new ChangeTaxStrategyCommand(city,TaxType::Flat);
            reportC = new CityReportCommand(city, city_report);
            incTrC = new IncreaseTransportCommand(city,VehicleType::Taxi);
            repairC = new RepairUtilitiesCommand(city);
            upC = new UpgradeUtilitiesCommand(city);
        }
        
        void TearDown() override {
            delete buildC;
            delete strategyC;
            delete reportC;
            delete incTrC;
            delete repairC;
            delete upC;
        }
};

// Test Constructor
TEST_F(government_test, construction_test) {
    EXPECT_EQ(city->getState(),CityState::Happy);
    EXPECT_EQ(city->checkCityFunds(),20000);
    EXPECT_EQ(city->getCitizenCount(),0);
    EXPECT_EQ(city->getWorkerCount(),0);
    EXPECT_EQ(city->getBuildingCount(),0);

    city->startTaxCycle();
    EXPECT_EQ(city->checkCityFunds(),20000);

    EXPECT_EQ(city->getCitizenHappiness(),0);
    city->setCitizenHappiness(100);
    EXPECT_EQ(city->getCitizenHappiness(),100);
    city->calculateHappiness();
    EXPECT_EQ(city->getCitizenHappiness(),0);
    EXPECT_EQ(city->getState(),CityState::Upset);

    city->removeLastBuilding();

}

TEST_F(government_test, tax_test) {
    EXPECT_EQ(city->checkCityFunds(),20000);
    city->startTaxCycle();
    EXPECT_EQ(city->checkCityFunds(),20000);
    city->addBuilding(BuildingType::BrickFactory);
    city->startTaxCycle();
    EXPECT_GT(city->checkCityFunds(),20000);
    EXPECT_GT(city->getCitizenCount(),0);
    EXPECT_GT(city->getWorkerCount(),0);
    EXPECT_EQ(city->getBuildingCount(),1);
}

TEST_F(government_test, utility_test) {
    city->checkUtilityUsage();
    city->upgradeUtilities();
    city->repairUtilities();
    std::string s = "";
    city->getUtilityStats(s);
}

TEST_F(government_test, transport_test) {
    std::string temp = "";
    city->generateReport(temp);

    std::cout << temp << std::endl;

    city->increaseTransport(VehicleType::Train);
    city->increaseTransport(VehicleType::Taxi);

    buildC->execute();
    strategyC->execute();
    reportC->execute();
    incTrC->execute();
    repairC->execute();
    upC->execute();

}

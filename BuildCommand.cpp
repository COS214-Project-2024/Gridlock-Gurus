#include "BuildCommand.h"
#include "City.h"
#include "BuildingFactory.h"
#include <iostream>

BuildCommand::BuildCommand(City* city, BuildingFactory* factory, const std::string& buildingType)
    : city(city), buildingFactory(factory), buildingType(buildingType) {}

BuildCommand::~BuildCommand() {
    // Cleanup resources if necessary
}

void BuildCommand::execute() {
    Building* building = buildingFactory->createBuilding(buildingType);
    if (building != nullptr) {
        city->addBuilding(building);
        std::cout << "Built a new " << buildingType << " in the city." << std::endl;
    }
}

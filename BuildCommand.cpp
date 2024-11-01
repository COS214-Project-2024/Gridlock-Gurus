#include "BuildCommand.h"
#include "City.h"
#include "Director.h"
#include "BuildingFactory.h"
#include <iostream>

BuildCommand::BuildCommand(City* city, Director* director, BuildingFactory* factory, const std::string& buildingType)
    : city(city), director(director), buildingFactory(factory), buildingType(buildingType) {}

BuildCommand::~BuildCommand() {
    // Cleanup resources if necessary
}

void BuildCommand::execute() {
    Building* building = buildingFactory->createBuilding(buildingType);
    if (building != NULL) {
        CityBuilder CityBuilder(building);
        director->setBuiding(&builder);

        if (buildingType == "Residential") {
            director->constructResidentialArea();
        } else if (buildingType == "Commercial") {
            director->constructCommercialArea();
        } else if (buildingType == "Infrastructure") {
            director->constructInfrastructure();
        }
        
        std::cout << "Built a new " << buildingType << " in the city." << std::endl;
        
        city->addBuilding(building);
    }
}

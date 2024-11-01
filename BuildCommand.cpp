#include "BuildCommand.h"
#include "City.h"
#include "Director.h"
#include "BuildingFactory.h"
#include <iostream>

BuildCommand::BuildCommand(City* city, Director* director, BuildingFactory* factory, const std::string& buildingType)
    : city(city), director(director), buildingFactory(factory), buildingType(buildingType) {}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute() {
    Command::execute();  // Update status
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

void BuildCommand::undo() {
    Command::undo();
    std::cout << "Undoing last constructed building" << std::endl;
    city->removeLastBuilding();
}

void BuildCommand::redo() {
    Command::redo();
    std::cout << "Redoing the construction of the last building." << std::endl;
    execute(); 
}

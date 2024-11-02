#include "BuildCommand.h"

void BuildCommand::execute() {
    //Command::execute();  // Update status
    status = EXECUTED;
    executionCount++;

    constructedBuilding = buildingFactory.createBuilding(buildingType,citizen);

    if (constructedBuilding != nullptr) {
        //CityBuilder CityBuilder(building);
        director.setBuilding(*constructedBuilding);

        if (buildingType == BuildingType::House || buildingType == BuildingType::Flat ||  buildingType == BuildingType::Estate ) {
            //director.constructResidentialArea();
        } else if (buildingType == BuildingType::Bank ||buildingType == BuildingType::Shop ) {
            //director.constructCommercialArea();
        } else {
            //director.constructInfrastructure();
        }
        
        city.addBuilding(*constructedBuilding);
    }
}

void BuildCommand::undo() {
    //Command::undo();
    if (status == EXECUTED) {
        status = UNDONE;
    }
    city.removeLastBuilding();
}

void BuildCommand::redo() {
    //Command::redo();
    if (status == UNDONE) {
        status = PENDING;
    }
    execute(); 
}

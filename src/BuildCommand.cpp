#include "BuildCommand.h"

void BuildCommand::execute() {
    status = EXECUTED;
    executionCount++;
    city.addBuilding(buildingType);
}

void BuildCommand::undo() {
    if (status == EXECUTED) {
        status = UNDONE;
    }
    city.removeLastBuilding();
}

void BuildCommand::redo() {
    if (status == UNDONE) {
        status = PENDING;
    }
    execute(); 
}

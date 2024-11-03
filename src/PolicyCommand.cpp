#include "PolicyCommand.h"
#include <string>
#include <iostream>


void PolicyCommand::execute() {
    status = EXECUTED;
    previousHappiness = city.getCitizenHappiness();
    city.setCitizenHappiness(previousHappiness + 10);
    //std::cout << "Implemented the " << policyName << " policy." << std::endl;
}

void PolicyCommand::undo() {
    status = UNDONE;

    city.setCitizenHappiness(previousHappiness);
    //std::cout << "Undid the " << policyName << " policy, restoring happiness." << std::endl;
}

void PolicyCommand::redo() {
    status = PENDING;

   city.setCitizenHappiness(previousHappiness + 10);
    //std::cout << "Redid the " << policyName << " policy, increasing happiness again." << std::endl;
}

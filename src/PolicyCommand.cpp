#include "PolicyCommand.h"
#include <string>
#include <iostream>


void PolicyCommand::execute() {
    status = EXECUTED;

    // Store current happiness level and apply policy
    previousHappiness = city->getCitizenHappiness();
    // Simulate implementing a policy.
    city->setCitizenHappiness(previousHappiness + 10);  // Example: increasing happiness.
    //std::cout << "Implemented the " << policyName << " policy." << std::endl;
}

void PolicyCommand::undo() {
    status = UNDONE;

    // Revert to the previous happiness level
    city->setCitizenHappiness(previousHappiness);
    //std::cout << "Undid the " << policyName << " policy, restoring happiness." << std::endl;
}

void PolicyCommand::redo() {
    status = PENDING;

    // Reapply the policy effect on happiness
   city->setCitizenHappiness(previousHappiness + 10);
    //std::cout << "Redid the " << policyName << " policy, increasing happiness again." << std::endl;
}

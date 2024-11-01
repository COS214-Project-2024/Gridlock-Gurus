#include "PolicyCommand.h"
#include "City.h"
#include <string>
#include <iostream>

PolicyCommand::PolicyCommand(City* city, const std::string& policyName)
    : city(city), policyName(policyName), , previousHappiness(0) {}

PolicyCommand::~PolicyCommand() {}

void PolicyCommand::execute() {
    Command::execute();  // Update status

    // Store current happiness level and apply policy
    previousHappiness = city->getCitizenHappiness();
    // Simulate implementing a policy.
    city->setCitizenHappiness(previousHappiness + 10);  // Example: increasing happiness.
    std::cout << "Implemented the " << policyName << " policy." << std::endl;
}

void PolicyCommand::undo() {
    Command::undo();  // Update status and logging

    // Revert to the previous happiness level
    city->setCitizenHappiness(previousHappiness);
    std::cout << "Undid the " << policyName << " policy, restoring happiness." << std::endl;
}

void PolicyCommand::redo() {
    Command::redo();  // Update status and logging

    // Reapply the policy effect on happiness
    city->setCitizenHappiness(previousHappiness + 10);
    std::cout << "Redid the " << policyName << " policy, increasing happiness again." << std::endl;
}

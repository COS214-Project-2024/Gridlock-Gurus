#include "PolicyCommand.h"
#include <iostream>

PolicyCommand::PolicyCommand(City* city, const std::string& policyName)
    : city(city), policyName(policyName) {}

PolicyCommand::~PolicyCommand() {
    // Cleanup resources if necessary
}

void PolicyCommand::execute() {
    // Simulate implementing a policy.
    city->CitizenHappiness(city->CitizenHappiness() + 10);  // Example: increasing happiness.
    std::cout << "Implemented the " << policyName << " policy." << std::endl;
}

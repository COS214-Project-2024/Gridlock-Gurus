#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H

#include "Command.h"
#include "City.h"
#include <string>
class PolicyCommand : public Command {
    City& city;
    std::string policyName;
    int previousHappiness;

public:
    PolicyCommand(City& city, const std::string& policyName): city(city), policyName(policyName), previousHappiness(0) {}
    ~PolicyCommand()override = default;
    void execute() override;
    void undo() override;
    void redo() override;
};

#endif // POLICYCOMMAND_H

#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H

#include "Command.h"
#include "City.h"
#include <string>
/**
 * @brief Command to handle the implementation of government policies.
 *
 * ConcreteCommand participant in the Command design pattern. It implements the `execute()` method to handle the enforcement of government policies.
 */
class PolicyCommand : public Command {
    City& city;
    std::string policyName;
    int previousHappiness;

public:
    /**
     * @brief Constructs a new PolicyCommand object.
     */
    PolicyCommand(City& city, const std::string& policyName): city(city), policyName(policyName), previousHappiness(0) {}

    /**
     * @brief Destroys the PolicyCommand object.
     */
    ~PolicyCommand()override = default;

    /**
     * @brief Executes the command to implement a policy.
     */
    void execute() override;

       /**
     * @brief Undo functionality.
     */
    void undo() override;

    /**
     * @brief Redo functionality.
     */
    void redo() override;
};

#endif // POLICYCOMMAND_H

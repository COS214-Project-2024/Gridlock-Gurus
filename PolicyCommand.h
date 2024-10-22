#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H

#include "Command.h"

/**
 * @brief Command to handle the implementation of government policies.
 */
class PolicyCommand : public Command {
public:
    PolicyCommand();  ///< Constructor
    ~PolicyCommand();  ///< Destructor
};

#endif // POLICYCOMMAND_H

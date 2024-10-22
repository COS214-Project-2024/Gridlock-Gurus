#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"

/**
 * @brief Command to handle the construction of buildings in the city.
 */
class BuildCommand : public Command {
public:
    BuildCommand();  ///< Constructor
    ~BuildCommand();  ///< Destructor
};

#endif // BUILDCOMMAND_H


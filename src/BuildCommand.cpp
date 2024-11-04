/**
* @class BuildCommand
 * @brief Definition of the BuildCommand class, which encapsulates a command to build structures in the city.
 */

#include "BuildCommand.h"

/**
 * @brief Executes the build command, adding a building to the city.
 */
void BuildCommand::execute() {
    std::string name = ""; // Building name (to be defined later)
    city->addBuilding(name,type);
}

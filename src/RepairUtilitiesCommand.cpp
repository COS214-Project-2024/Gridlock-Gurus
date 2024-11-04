#include "RepairUtilitiesCommand.h"

/**
 * @brief Executes the command to repair all utilities in the city.
 *
 * This function calls the `repairUtilities` method on the city object,
 * restoring utilities to full functionality.
 */
void RepairUtilitiesCommand::execute() {
    city->repairUtilities();
}

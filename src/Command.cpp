#include "Command.h"
#include <iostream>

/*
 * @brief Marks the command as executed and increments the execution count.
 *
 * This function updates the status of the command to EXECUTED
 * and increments the execution count.
 */
/*void Command::executed() {
    status = EXECUTED;
    executionCount++;

}*/

/**
 * @brief Undoes the last executed command.
 *
 * This function sets the status of the command to UNDONE if it was
 * previously EXECUTED, effectively reversing its action.
 */
/*void Command::undo() {
    // Set status to UNDONE and log the undo action
    if (status == EXECUTED) {
        status = UNDONE;
        //std::cout << "Command undone" << std::endl;
    }
}*/

/**
 * @brief Redoes the last undone command.
 *
 * This function re-executes the command if its status is UNDONE,
 * restoring its previous state.
 */
/*void Command::redo() {
    if (status == UNDONE) {
        // Re-execute the command and set status back to EXECUTED
        //execute();
        //std::cout << "Command redone" << std::endl;
    }
}*/

/**
 * @brief Retrieves the current status of the command.
 *
 * @return The current status of the command as a Status enum.
 */
/*Status Command::getStatus() const {
    return status;
}*/

/**
 * @brief Retrieves the execution count of the command.
 *
 * @return The number of times the command has been executed.
 */
/*int Command::getExecutionCount() const {
    return executionCount;
}
*/

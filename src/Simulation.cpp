#include "Simulation.h"


/**
 * @brief Stores and executes a command from the queue.
 *
 * @param cmd The command to be stored and executed.
 */
void Simulation::storeAndExecute(std::unique_ptr<Command> cmd) {
    commandQueue.push(std::move(cmd));
    
    cmd->execute();
    
    commandQueue.pop();
}

#include "Simulation.h"

void Simulation::storeAndExecute(std::unique_ptr<Command> cmd) {
    commandQueue.push(std::move(cmd));
    
    cmd->execute();
    
    commandQueue.pop();
}

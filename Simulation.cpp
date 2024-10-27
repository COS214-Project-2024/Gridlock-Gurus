#include "Simulation.h"

void Simulation::storeAndExecute(Command* cmd) {
    commandQueue.push(cmd);
    
    cmd->execute();
    
    commandQueue.pop();
}

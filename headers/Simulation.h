#ifndef SIMULATION_H
#define SIMULATION_H

#include "Command.h"
#include <queue>

/**
 * @brief Manages the simulation of city activities.
 *
 * Invoker participant in the Command design pattern. It stores and executes commands that represent different actions in the city simulation.
 */
class Simulation {
private:
    std::queue<Command*> commandQueue;  ///< Queue of commands to be executed.

public:
    /**
     * @brief Stores a command and executes it.
     * @param cmd The command to store and execute.
     *
     * This function is responsible for storing a command and then executing it as part of the simulation.
     */
    void storeAndExecute(Command* cmd);
};

#endif // SIMULATION_H

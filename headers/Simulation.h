#ifndef SIMULATION_H
#define SIMULATION_H

#include "Command.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include "FactoryFactory.h"
#include "LandmarkFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "ServiceFactory.h"
#include "City.h"

#include <queue>
#include <memory>

/**
 * @brief Manages the simulation of city activities.
 *
 * Invoker participant in the Command design pattern. It stores and executes commands that represent different actions in the city simulation.
 */
class Simulation {
private:
    //std::queue<Command*> commandQueue;  ///< Queue of commands to be executed.
    std::queue<std::unique_ptr<Command>> commandQueue;
    City& city;

public:
    Simulation(City& city) : city(city) {}

    /**
     * @brief Stores a command and executes it.
     * @param cmd The command to store and execute.
     *
     * This function is responsible for storing a command and then executing it as part of the simulation.
     */
    void storeAndExecute(std::unique_ptr<Command> cmd);

    ~Simulation() {
        /*while (!commandQueue.empty()) {
            Command* cmd = commandQueue.front();
            delete cmd; 
            commandQueue.pop();    
        }*/
    }
};

#endif // SIMULATION_H

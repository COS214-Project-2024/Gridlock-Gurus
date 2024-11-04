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
 * @class Simulation
 * @brief Represents the simulation of a city, managing and executing commands.
 */
class Simulation {
private:
    std::queue<std::unique_ptr<Command>> commandQueue;  ///< Queue of commands to be executed.
    City& city;                                         ///< Reference to the city being simulated.

public:
    /**
     * @brief Constructs a new Simulation object.
     * @param city Reference to the city to be simulated.
     */
    Simulation(City& city) : city(city) {}

    /**
     * @brief Stores and executes a command.
     * 
     * @param cmd Unique pointer to the command to be executed.
     */
    void storeAndExecute(std::unique_ptr<Command> cmd);

    /**
     * @brief Destroys the Simulation object.
     */
    ~Simulation() {
        /*while (!commandQueue.empty()) {
            Command* cmd = commandQueue.front();
            delete cmd; 
            commandQueue.pop();    
        }*/
    }
};

#endif // SIMULATION_H
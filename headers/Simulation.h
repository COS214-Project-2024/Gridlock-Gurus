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

class Simulation {
private:
    //std::queue<Command*> commandQueue;  ///< Queue of commands to be executed.
    std::queue<std::unique_ptr<Command>> commandQueue;
    City& city;

public:
    Simulation(City& city) : city(city) {}
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

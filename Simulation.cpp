#include "Simulation.h"
#include "City.h"
#include "BuildingFactory.h"
#include "TaxAuthority.h"

Simulation::Simulation(City* city, BuildingFactory* factory, TaxAuthority* taxAuth)
    : city(city), buildingFactory(factory), taxAuthority(taxAuth) {}

void Simulation::storeAndExecute(Command* cmd) {
    commandQueue.push(cmd);
    
    cmd->execute();
    
    commandQueue.pop();
}

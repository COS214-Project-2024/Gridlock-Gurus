#include "FactoryFactory.h"
#include "Building.h"
#include "Factory.h"
#include "BrickFactory.h"
#include "SteelFactory.h"
#include "WoodFactory.h"
#include <string>

// Made citizen a reference instead of pointer to prevent it being nullptr
Building *FactoryFactory::createBuilding(BuildingType type, Citizen& owner) {
    Resources* resources = new Resources(200,200,false);
    int maxEmployees;
    int productionRate;
    int cost;
    std::string location = "Factory district";

    if(type == BuildingType::WoodFactory) {
        maxEmployees = 100;
        cost = 100;
        productionRate = 4;

        Building* b = new WoodFactory(cost, location,resources, 1000, owner, type,productionRate, maxEmployees);
        taxAuthority->registerBuilding(*b);
        return b; 
    } else if(type == BuildingType::SteelFactory) {
        maxEmployees = 100;
        cost = 1000;
        productionRate = 6;

        Building* b = new SteelFactory(cost, location,resources, 1000, owner,type,productionRate, maxEmployees);
        taxAuthority->registerBuilding(*b);
        return b; 

    } else {
        maxEmployees = 1000;
        cost = 500;
        productionRate = 12;

        Building* b = new BrickFactory(cost, location,resources, 1000, owner, type,productionRate, maxEmployees);
        taxAuthority->registerBuilding(*b);
        return b; 

    }
}

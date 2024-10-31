#include "FactoryFactory.h"
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
        cost = 500;
        productionRate = 4;
        return new WoodFactory(cost, location,resources, 1000, owner, taxAuthority,productionRate, maxEmployees);
      
    } else if(type == BuildingType::SteelFactory) {
        maxEmployees = 100;
        cost = 1000;
        productionRate = 6;
        return new SteelFactory(cost, location,resources, 1000, owner, taxAuthority,productionRate, maxEmployees);
       
    } else {
        maxEmployees = 1000;
        cost = 1500;
        productionRate = 12;
        return new BrickFactory(cost, location,resources, 1000, owner, taxAuthority,productionRate, maxEmployees);

    }
}

#include "Commercial.h"
#include "CommercialFactory.h"
#include <iostream>
#include <ostream>

// Made citizen a reference instead of pointer to prevent it being nullptr
Building *CommercialFactory::createBuilding(BuildingType type, Citizen& owner) {
    Resources* resources = new Resources(100,100,true);
    int maxEmployees;
    int productionRate;
    int cost;
    std::string location = "Business district";

    // I changed it because before it returs a nullptr? checks should be done before calling, the function of factory is just to produce
    if(type == BuildingType::Bank) {
        maxEmployees = 30;
        cost = 100000;
        productionRate = 6;
        
    } else {
        maxEmployees = 60;
        cost = 120000;
        productionRate = 12;
    }

    return new Commercial(cost, temp,*resources, 1000, owner, taxAuthority, maxEmployees,productionRate);
}

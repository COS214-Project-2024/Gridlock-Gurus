#include "Commercial.h"
#include "CommercialFactory.h"
#include <string>

// Made citizen a reference instead of pointer to prevent it being nullptr
Building *CommercialFactory::createBuilding(const std::string& name,BuildingType type, Citizen& owner) {
    Resources* resources = new Resources(100,100,true);
    int maxEmployees;
    int productionRate;
    int cost;
    std::string location = "Business district";

    // I changed it because before it returs a nullptr? checks should be done before calling, the function of factory is just to produce
    if(type == BuildingType::Bank) {
        maxEmployees = 30;
        cost = 200;
        productionRate = 6;
        
    } else {
        maxEmployees = 60;
        cost = 100;
        productionRate = 12;
    }

    Commercial* c = new Commercial(name,cost, location,resources, 1000, owner, type,maxEmployees,productionRate);
    taxAuthority->registerBuilding(*c);
    return c;
}

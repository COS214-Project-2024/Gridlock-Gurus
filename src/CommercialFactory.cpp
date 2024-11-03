#include "Commercial.h"
#include "CommercialFactory.h"
#include <string>

Building *CommercialFactory::createBuilding(BuildingType type, Citizen& owner) {
    Resources* resources = new Resources(100,100,true);
    int maxEmployees;
    int productionRate;
    int cost;
    std::string location = "Business district";

    if(type == BuildingType::Bank) {
        maxEmployees = 30;
        cost = 200;
        productionRate = 6;
        
    } else {
        maxEmployees = 60;
        cost = 100;
        productionRate = 12;
    }

    Commercial* c = new Commercial(cost, location,resources, 1000, owner, type,maxEmployees,productionRate);
    taxAuthority->registerBuilding(*c);
    return c;
}

#include "Commercial.h"
#include "CommercialFactory.h"
#include <string>


/**
 * @brief Creates a new Commercial building based on the specified parameters.
 *
 * @param name The name of the building.
 * @param type The type of the building (Bank or other).
 * @param owner The citizen who will own the building.
 *
 * @return A pointer to the created Building object.
 */
Building *CommercialFactory::createBuilding(const std::string& name,BuildingType type, Citizen& owner) {
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

    Commercial* c = new Commercial(name,cost, location,resources, 1000, owner, type,maxEmployees,productionRate);
    taxAuthority->registerBuilding(*c);
    return c;
}

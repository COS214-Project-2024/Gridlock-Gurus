#include "FactoryFactory.h"
#include "Building.h"
#include "Factory.h"
#include "BrickFactory.h"
#include "SteelFactory.h"
#include "WoodFactory.h"
#include <string>


/**
 * @brief Creates a new building of the specified type.
 *
 * Allocates resources and creates a building of the given type with the
 * specified name and owner. The building is registered with the tax
 * authority upon creation.
 *
 * @param name The name of the building.
 * @param type The type of the building to create (Wood, Steel, or Brick Factory).
 * @param owner The Citizen who will own the building.
 * @return Pointer to the created Building object.
 */
Building *FactoryFactory::createBuilding(const std::string& name,BuildingType type, Citizen& owner) {
    Resources* resources = new Resources(200,200,false);
    int maxEmployees;
    int productionRate;
    int cost;
    std::string location = "Factory district";

    if(type == BuildingType::WoodFactory) {
        maxEmployees = 100;
        cost = 100;
        productionRate = 4;

        Building* b = new WoodFactory(name,cost, location,resources, 1000, owner, type,productionRate, maxEmployees);
        taxAuthority->registerBuilding(*b);
        return b; 
    } else if(type == BuildingType::SteelFactory) {
        maxEmployees = 100;
        cost = 1000;
        productionRate = 6;

        Building* b = new SteelFactory(name,cost, location,resources, 1000, owner,type,productionRate, maxEmployees);
        taxAuthority->registerBuilding(*b);
        return b; 

    } else {
        maxEmployees = 100;
        cost = 500;
        productionRate = 12;

        Building* b = new BrickFactory(name,cost, location,resources, 1000, owner, type,productionRate, maxEmployees);
        taxAuthority->registerBuilding(*b);
        return b; 

    }
}

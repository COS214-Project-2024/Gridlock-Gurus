#include "WoodFactory.h"

/**
 * @brief Constructs a WoodFactory with specified properties.
 *
 * @param name Name of the factory.
 * @param cost Cost to build the factory.
 * @param location Location of the factory.
 * @param resources Pointer to the factory's resource pool.
 * @param size Size of the factory.
 * @param owner Reference to the citizen who owns the factory.
 * @param type Type of the building (WoodFactory).
 * @param productionRate Production rate of the factory.
 * @param max Maximum production capacity.
 */
WoodFactory::WoodFactory(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) : Factory(name,cost, location, resources, size, owner,type, productionRate, max){}

/**
 * @brief Produces resources from the WoodFactory.
 *
 * @return The amount of resources produced (default is 100).
 */
int WoodFactory::produceResource() {
    return 100;
}

/**
 * @brief Calculates the tax payment for the WoodFactory.
 *
 * @return The tax payment amount (default is 90).
 */
int WoodFactory::pay() {
    return 90;
}



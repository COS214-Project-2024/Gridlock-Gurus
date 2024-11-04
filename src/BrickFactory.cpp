/**
* @class BrickFactory
 * @brief Definition of the BrickFactory class, which produces bricks.
 */

#include "BrickFactory.h"

/**
 * @brief Constructs a BrickFactory object.
 *
 * @param name The name of the brick factory.
 * @param cost The cost associated with the factory.
 * @param location The geographical location of the factory.
 * @param resources Pointer to the resources available for the factory.
 * @param size The size of the factory.
 * @param owner Reference to the citizen who owns the factory.
 * @param type The building type of the factory.
 * @param productionRate The rate at which the factory produces resources.
 * @param max The maximum number of employees the factory can have.
 */
BrickFactory::BrickFactory(const std::string& name, int cost, std::string& location, Resources *resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) : Factory(name,cost, location, resources, size, owner ,type, productionRate, max){}

/**
 * @brief Produces a fixed amount of bricks.
 *
 * @return An integer representing the number of bricks produced.
 */
int BrickFactory::produceResource() {
    return 100;
}

/**
 * @brief Processes the payment for the brick factory.
 *
 * @return An integer representing the payment amount.
 */
int BrickFactory::pay() {
    return 100;
}

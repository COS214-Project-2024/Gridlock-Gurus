#ifndef STEELFACTORY_H
#define STEELFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"
#include <vector>
#include <string>

/**
 * @class SteelFactory
 * @brief Represents a factory that produces steel.
 */
class SteelFactory : public Factory {
public:
    /**
     * @brief Constructs a new SteelFactory object.
     * 
     * @param name The name of the factory.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Reference to the factory's owner.
     * @param type The type of building.
     * @param productionRate The rate of production for steel.
     * @param max The maximum production capacity.
     */
    SteelFactory(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) 
    : Factory(name, cost, location, resources, size, owner, type, productionRate, max) {}

    /**
     * @brief Destroys the SteelFactory object.
     */
    ~SteelFactory() override = default;

    /**
     * @brief Produces steel in the factory.
     * @return The amount of steel produced.
     */
    int produceResource() override;

    /**
     * @brief Pays the factory workers or operational costs.
     * @return The payment amount.
     */
    int pay() override;
};

#endif // STEELFACTORY_H
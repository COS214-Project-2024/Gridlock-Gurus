#ifndef WOODFACTORY_H
#define WOODFACTORY_H

#include "BuildingType.h"
#include "Building.h"
#include "Factory.h"

#include <vector>
#include <string>

/**
 * @class WoodFactory
 * @brief Represents a factory specialized in producing wood resources.
 */

class WoodFactory : public Factory {
public:
    /**
     * @brief Constructs a new WoodFactory object.
     * 
     * @param name The name of the factory.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Reference to the factory's owner.
     * @param type The type of building this factory represents.
     * @param productionRate The rate at which the factory produces wood.
     * @param max The maximum production capacity of the factory.
     */
    WoodFactory(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max);

    /**
     * @brief Destroys the WoodFactory object.
     */
    ~WoodFactory() override = default;

    /**
     * @brief Produces wood in the factory.
     * @return The amount of wood produced.
     */
    int produceResource() override;

    /**
     * @brief Handles the payment process for the factory.
     * @return The amount paid.
     */
    int pay() override;
};

#endif // WOODFACTORY_H
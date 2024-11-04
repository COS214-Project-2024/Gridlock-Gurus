#ifndef BRICKFACTORY_H
#define BRICKFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"
#include <vector>
#include <string>

/**
 * @class BrickFactory
 * @brief A factory specialized in producing bricks, inheriting from the Factory base class.
 */
class BrickFactory : public Factory {
public:
    /**
     * @brief Constructs a new BrickFactory object.
     * @param name The name of the factory.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Reference to the factory's owner.
     * @param type The type of building the factory represents.
     * @param productionRate The rate at which bricks are produced.
     * @param max The maximum production capacity.
     */
    BrickFactory(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max);

    /**
     * @brief Destroys the BrickFactory object.
     */
    ~BrickFactory() override = default;

    /**
     * @brief Produces resources (bricks) and returns the amount produced.
     * @return The amount of resources produced.
     */
    int produceResource() override;

    /**
     * @brief Calculates and returns the payment required for production.
     * @return The payment amount.
     */
    int pay() override;
};

#endif // BRICKFACTORY_H

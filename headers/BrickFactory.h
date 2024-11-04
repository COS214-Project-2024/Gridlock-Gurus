#ifndef BRICKFACTORY_H
#define BRICKFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"
#include <vector>
#include <string>

class BrickFactory : public Factory {
public:
    /**
     * @brief Constructs a new BrickFactory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    BrickFactory(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner ,BuildingType type, int productionRate, int max);

    /**
     * @brief Destroys the BrickFactory object.
     */
     ~BrickFactory() override = default;
    int produceResource() override;
    int pay() override;
};

#endif // BRICKFACTORY_H

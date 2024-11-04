#ifndef STEELFACTORY_H
#define STEELFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"

#include <vector>
#include <string>

class SteelFactory : public Factory {
public:
    /**
     * @brief Constructs a new SteelFactory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    SteelFactory(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) 
    : Factory(name,cost, location, resources,size,owner,type,productionRate,max) {};

    /**
     * @brief Destroys the SteelFactory object.
     */
    ~SteelFactory() override = default;
    /**
     * @brief Produces steel in the factory.
     */
    int produceResource() override;
     int pay() override;

};

#endif // STEELFACTORY_H

#ifndef STEELFACTORY_H
#define STEELFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"

#include <vector>
#include <string>

class SteelFactory : public Factory {
public:
    SteelFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name, int productionRate, int max) 
    : Factory(cost, location, resources,size,owner,name,productionRate,max) {};
    ~SteelFactory() override = default;
    /**
     * @brief Produces steel in the factory.
     */
    int produceResource() override;
     int pay() override;

};

#endif // STEELFACTORY_H

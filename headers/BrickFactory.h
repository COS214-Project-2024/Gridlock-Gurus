#ifndef BRICKFACTORY_H
#define BRICKFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"
#include <vector>
#include <string>

class BrickFactory : public Factory {
public:
    BrickFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner ,BuildingType name, int productionRate, int max);
     ~BrickFactory() override = default;
    int produceResource() override;
    int pay() override;
};

#endif // BRICKFACTORY_H

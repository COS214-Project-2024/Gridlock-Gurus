#ifndef WOODFACTORY_H
#define WOODFACTORY_H

#include "BuildingType.h"
#include "Building.h"
#include "Factory.h"

#include <vector>
#include <string>

class WoodFactory : public Factory {
public:
    WoodFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType name, int productionRate, int max);

     ~WoodFactory() override = default;

    std::string getDetails() const override;

    int produceResource() override;

     int pay() override;
};

#endif // WOODFACTORY_H

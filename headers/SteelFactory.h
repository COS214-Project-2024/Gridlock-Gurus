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
    std::string getDetails() const override;
    int produceResource() override;
     int pay() override;

};

#endif // STEELFACTORY_H

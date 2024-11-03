#include "BrickFactory.h"

BrickFactory::BrickFactory(int cost, std::string& location, Resources *resources, int size, Citizen& owner,BuildingType name, int productionRate, int max) : Factory(cost, location, resources, size, owner ,name, productionRate, max){}

int BrickFactory::produceResource() {
    return 100;
}

int BrickFactory::pay() {
    return 100;
}


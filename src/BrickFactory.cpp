#include "BrickFactory.h"


BrickFactory::BrickFactory(const std::string& name, int cost, std::string& location, Resources *resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) : Factory(name,cost, location, resources, size, owner ,type, productionRate, max){}

int BrickFactory::produceResource() {
    return 100;
}

int BrickFactory::pay() {
    return 100;
}

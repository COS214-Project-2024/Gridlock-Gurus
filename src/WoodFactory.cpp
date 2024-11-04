#include "WoodFactory.h"

WoodFactory::WoodFactory(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) : Factory(name,cost, location, resources, size, owner,type, productionRate, max){}


int WoodFactory::produceResource() {
    return 100;
}

int WoodFactory::pay() {
    return 90;
}



#include "WoodFactory.h"

WoodFactory::WoodFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name, int productionRate, int max) : Factory(cost, location, resources, size, owner,name, productionRate, max){}


int WoodFactory::produceResource() {
    return 100;
}

int WoodFactory::pay() {
    return 90;
}



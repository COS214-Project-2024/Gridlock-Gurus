#include "Building.h"

Building::Building(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name)
    : cost(cost), location(location), resources(resources), size(size), owner(&owner), name(name) {}

Building::~Building() {
    if(owner) {
        //delete owner;
    }
    delete resources;
}

int Building::pay() {
    return 0;
}


void Building::payTax(int amount) {
    if(owner) {
        this->owner->payTaxes(amount);
    }
}


int Building::getCost() const {
    return this->cost;
}

std::string Building::getLocation() const {
    return this->location;
}

int Building::getSize() const {
    return this->size;
}

BuildingType Building::getName() const {
    return name;
}



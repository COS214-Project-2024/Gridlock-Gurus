#include "Building.h"

Building::Building(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type)
    : name(name), cost(cost), location(location), resources(resources), size(size), owner(&owner), type(type) {}

Building::~Building() {
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

BuildingType Building::getType() const {
    return type;
}

std::string Building::getDetails() const {
    std::string details = "";
    details += "Building Name:\t";
    details += name;
    details += "\nLocation:\t";
    details += location;
    return details;
}


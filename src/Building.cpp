#include "Building.h"

Building::Building(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name)
    : cost(cost), location(location), resources(resources), size(size), owner(owner), name(name) {}

Building::~Building() {
    delete resources;
}

std::string Building::getDetails() const {
    std::string details =  "";
    details += "Owner:\t" + owner.getName() + "\n";
    details += "Location:\t" + location + "\n";
    details += "Cost:\t" + std::to_string(cost) + "\n";
    details += "Size:\t" + std::to_string(size) + "\n";
    return details;;
}

int Building::pay() {
    return 0;
}


void Building::payTax(int amount) {
    this->owner.payTaxes(amount);
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



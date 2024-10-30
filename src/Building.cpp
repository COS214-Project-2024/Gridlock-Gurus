#include "Building.h"

Building::Building(int cost,std::string location, Resources* resources, int size,Citizen* owner,std::weak_ptr<TaxAuthority> taxAuthority) {
    this->cost = cost;
    this->location = location;
    this->resources = resources;
    this->size = size;
    this->owner = owner;
    this->taxAuthority = taxAuthority;
}

void Building::payTax(int amount){
    this->owner->payTaxes(amount);
}

int Building::getCost() {
    return this->cost;
}

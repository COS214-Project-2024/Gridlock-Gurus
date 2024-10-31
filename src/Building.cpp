#include "Building.h"

Building::Building(int cost,std::string& location, Resources* resources, int size,Citizen* owner,TaxAuthority* taxAuthority) {
    this->cost = cost;
    this->location = location;
    this->resources = resources;
    this->size = size;
    this->owner = owner;
    this->taxAuthority = taxAuthority;
}

std::string Building::getDetails() {

}

int Building::pay() {
    return 0;
}


void Building::payTax(int amount){
    this->owner->payTaxes(amount);
}


int Building::getCost() {
    return this->cost;
}

std::string Building::getLocation() {
    return this->location;
}

int Building::getSize() {
    return this->size;
}



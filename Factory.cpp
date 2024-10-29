#include "Factory.h"

Factory::Factory(int cost, std::string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, int productionRate, int max) : Building(cost, location, resources, size, owner, taxAuthority){
    this->cost = cost;
    this->location = location;
    this->resources = resources;
    this->size = size;
    this->owner = owner;
    this->taxAuthority = taxAuthority;
    this->productionRate = productionRate;
    this->numOfEmployees = 0;
    this->maxEmployees = max;
}

#include "Factory.h"

Factory::Factory(int cost, std::string location, Resources *resources, int size, Citizen *owner, std::weak_ptr<TaxAuthority> taxAuthority, int productionRate, int max) : Building(cost, location, resources, size, owner, taxAuthority){
    this->productionRate = productionRate;
    this->numOfEmployees = 0;
    this->maxEmployees = max;
}

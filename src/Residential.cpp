#include "Residential.h"
#include <algorithm>
#include <iostream>

Residential::Residential(int cost, std::string& location, Resources *resources, int size, Citizen& owner,BuildingType name, int capacity) : Building(cost, location, resources, size, owner,name) {
    this->maxCapacity = capacity;
}

void Residential::addTenant(Citizen& tenant) {
    if(tenants.size() < maxCapacity) {
        tenants.push_back(tenant.getId());
        tenant.setHome(*this);
    }
}

void Residential::removeTenant(Citizen& tenant) {
    auto it = std::find(tenants.begin(), tenants.end(), tenant.getId());

    if(it != tenants.end()) {
        tenants.erase(it);
    }
}

bool Residential::isFull() const {
    return tenants.size() >= maxCapacity;
}

#include "Residential.h"
#include <algorithm>
#include <iostream>

Residential::Residential(int cost, std::string& location, Resources *resources, int size, Citizen& owner,BuildingType name, int capacity) : Building(cost, location, resources, size, owner,name) {
    this->maxCapacity = capacity;
}

std::string Residential::getDetails() const {
    std::string details =  "Residential: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(tenants.size()) + "/" + std::to_string(maxCapacity) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void Residential::addTenant(Citizen& tenant) {
    if(tenants.size() < maxCapacity) {
        tenants.push_back(&tenant);
        tenant.setHome(*this);
    }
}

void Residential::removeTenant(Citizen& tenant) {
    auto it = std::find(tenants.begin(), tenants.end(), &tenant);

    if(it != tenants.end()) {
        tenants.erase(it);
    }
}

bool Residential::isFull() const {
    return tenants.size() >= maxCapacity;
}

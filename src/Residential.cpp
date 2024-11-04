#include "Residential.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Constructs a Residential building with specified attributes.
 *
 * @param name The name of the residential building.
 * @param cost The construction cost of the building.
 * @param location The location of the building.
 * @param resources Pointer to the resources associated with the building.
 * @param size The size of the building.
 * @param owner Reference to the citizen who owns the building.
 * @param type The type of building (e.g., Flat, House, Estate).
 * @param capacity The maximum capacity for tenants in the building.
 */
Residential::Residential(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner,BuildingType type, int capacity) : Building(name,cost, location, resources, size, owner,type) {
    this->maxCapacity = capacity;
}

/**
 * @brief Adds a tenant to the residential building if capacity allows.
 *
 * @param tenant The tenant to be added to the building.
 */
void Residential::addTenant(Citizen& tenant) {
    if(tenants.size() < maxCapacity) {
        tenants.push_back(tenant.getId());
        tenant.setHome(*this);
    }
}

/**
 * @brief Removes a tenant from the residential building.
 *
 * @param tenant The tenant to be removed from the building.
 */
void Residential::removeTenant(Citizen& tenant) {
    auto it = std::find(tenants.begin(), tenants.end(), tenant.getId());

    if(it != tenants.end()) {
        tenants.erase(it);
    }
}

/**
 * @brief Checks if the residential building is at full capacity.
 *
 * @return True if the building is full, otherwise false.
 */
bool Residential::isFull() const {
    return tenants.size() >= maxCapacity;
}

/**
 * @brief Retrieves the list of tenant IDs in the residential building.
 *
 * @return A reference to the vector of tenant IDs.
 */
std::vector<int>& Residential::getTenants() {
    return tenants;
}

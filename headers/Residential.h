#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <vector>
#include <string>
#include <memory>

/**
 * @class Residential
 * @brief Represents a residential building that houses citizens.
 */
class Residential : public Building {
private:
    int maxCapacity;            ///< The maximum number of citizens the building can house.
    std::vector<int> tenants;   ///< List of tenant IDs living in the building.

public:
    /**
     * @brief Constructs a new Residential building object.
     * 
     * @param name The name of the building.
     * @param cost The construction cost.
     * @param location The location of the building.
     * @param resources Pointer to the resources used by the building.
     * @param size The size of the building.
     * @param owner Reference to the owner of the building.
     * @param type The type of building.
     * @param capacity The maximum capacity of tenants.
     */
    Residential(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int capacity);

    /**
     * @brief Destroys the Residential building object.
     */
    ~Residential() override = default;

    /**
     * @brief Adds a tenant to the residential building.
     * @param tenant Reference to the citizen to add as a tenant.
     */
    void addTenant(Citizen& tenant);

    /**
     * @brief Removes a tenant from the residential building.
     * @param tenant Reference to the citizen to remove as a tenant.
     */
    void removeTenant(Citizen& tenant);

    /**
     * @brief Checks if the building is full.
     * @return true if the building is full, false otherwise.
     */
    bool isFull() const;

    /**
     * @brief Gets the number of tenants in the building.
     * @return The number of tenants.
     */
    int getNumberOfTenants() const {
        return tenants.size();
    }

    /**
     * @brief Gets the list of tenant IDs.
     * @return Reference to the vector of tenant IDs.
     */
    std::vector<int>& getTenants();
};

#endif // RESIDENTIAL_H
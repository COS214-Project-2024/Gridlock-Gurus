#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <vector>
#include <string>
#include <memory>

class Residential : public Building {
private:
    int maxCapacity;  ///< The maximum number of citizens the building can house.
    //std::vector<Citizen*> tenants;  ///< List of tenants living in the building.
    std::vector<int> tenants;

public:
    Residential(int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType name, int capacity);

    /**
     * @brief Destroys the Residential building object.
     */
    ~Residential() override = default; 

    /**
     * @brief Adds a tenant to the residential building.
     * @param tenant Pointer to the citizen to add as a tenant.
     */
    void addTenant(Citizen& tenant);
    void removeTenant(Citizen& tenant);

    bool isFull() const;

    int getNumberOfTenants() const {
        return tenants.size();
    }
};

#endif // RESIDENTIAL_H

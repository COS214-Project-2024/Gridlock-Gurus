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
    /**
     * @brief Constructs a new Residential building object.
     * @param cost The construction cost.
     * @param location The location of the building.
     * @param resources Pointer to the resources used by the building.
     * @param size The size of the building.
     * @param owner Pointer to the citizen who owns the building.
     * @param taxAuthority Pointer to the tax authority.
     */
    Residential(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType type, int capacity);

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

    std::vector<int>& getTenants();

};

#endif // RESIDENTIAL_H

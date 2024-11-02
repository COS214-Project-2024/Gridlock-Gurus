#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <vector>
#include <string>
#include <memory>

/**
 * @brief Represents a residential building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It represents a specific type of building and adds features like managing tenants.
 */
class Residential : public Building {
private:
    int maxCapacity;  ///< The maximum number of citizens the building can house.
    std::vector<Citizen*> tenants;  ///< List of tenants living in the building.

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
    Residential(int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType name, int capacity);

    /**
     * @brief Destroys the Residential building object.
     */
    ~Residential() override = default;

    /**
     * @brief Gets details about the residential building.
     * @return A string containing details about the residential building.
     *
     * This method overrides the base `getDetails()` method to provide specific details for residential buildings.
     */
    std::string getDetails() const override;

    /**
     * @brief Calculates household tax for the residential building.
     * 
     * The calculated household tax.
     */
    //void householdTax();

    /**
     * @brief Adds a tenant to the residential building.
     * @param tenant Pointer to the citizen to add as a tenant.
     */
    void addTenant(Citizen& tenant);

    /**
        * @brief Adds a tenant to the residential building.
        * @param tenant Pointer to the citizen to add as a tenant.
        */
    void removeTenant(Citizen& tenant);

    bool isFull() const;

    int getNumberOfTenants() const {
        return tenants.size();
    }
};

#endif // RESIDENTIAL_H

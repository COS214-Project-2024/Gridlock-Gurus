#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <list>
#include <string>
using namespace std;

/**
 * @brief Represents a residential building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It represents a specific type of building and adds features like managing tenants.
 */
class Residential : public Building {
private:
    int maxCapacity;  ///< The maximum number of citizens the building can house.
    int capacity;  ///< The number of citizens currently in the building.
    list<Citizen*> tenants;  ///< List of tenants living in the building.

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
    Residential(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority, int capacity);

    /**
     * @brief Destroys the Residential building object.
     */
    virtual ~Residential() = default;

    /**
     * @brief Gets details about the residential building.
     * @return A string containing details about the residential building.
     *
     * This method overrides the base `getDetails()` method to provide specific details for residential buildings.
     */
    std::string getDetails() override;

    /**
     * @brief Pays taxes for the residential building.
     *
     * This method overrides the base `payTax()` method to implement tax payment for residential buildings.
     */
    void payTax(int amount) override;

    /**
     * @brief Calculates household tax for the residential building.
     * 
     * The calculated household tax.
     */
    void householdTax();

    /**
     * @brief Adds a tenant to the residential building.
     * @param tenant Pointer to the citizen to add as a tenant.
     */
    void addTenant(Citizen* tenant);

    /**
        * @brief Adds a tenant to the residential building.
        * @param tenant Pointer to the citizen to add as a tenant.
        */
    void removeTenant(Citizen* tenant);

    int pay(Citizen* employee) override;
    void update() override;
};

#endif // RESIDENTIAL_H
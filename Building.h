#ifndef BUILDING_H
#define BUILDING_H

#include "Resources.h"
#include "Citizen.h"
#include <string>
using namespace std;

/**
 * @brief Represents a building in the city.
 *
 * Product participant in the Factory Method pattern. It defines the properties and methods shared by all types of buildings.
 */
class Building {
protected:
    int cost;  ///< The construction cost of the building.
    std::string location;  ///< The location of the building.
    Resources* resources;  ///< Resources used by the building.
    int size;  ///< The size of the building.
    Citizen* owner;  ///< The owner of the building.
    TaxAuthority* taxAuthority;  ///< Tax authority associated with the building.

public:
    /**
     * @brief Constructs a new Building object.
     * @param cost The construction cost.
     * @param location The location of the building.
     * @param resources Pointer to the resources used by the building.
     * @param size The size of the building.
     * @param owner Pointer to the citizen who owns the building.
     * @param taxAuthority Pointer to the tax authority.
     */
    Building(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority);

    /**
     * @brief Destroys the Building object.
     */
    virtual ~Building() = default;

    /**
     * @brief Gets details about the building.
     * @return A string containing details about the building.
     */
    virtual std::string getDetails();

    /**
     * @brief Pays taxes on the building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
    virtual void payTax(int amount, Citizen* owner);
};

#endif // BUILDING_H
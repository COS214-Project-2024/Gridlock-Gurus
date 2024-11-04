/**
 * @class Building
 * @brief Definition of the Building class, representing a general building structure.
 */

#include "Building.h"

/**
 * @brief Constructs a Building object.
 *
 * @param name The name of the building.
 * @param cost The cost of constructing the building.
 * @param location The location of the building.
 * @param resources Pointer to the resources needed for the building.
 * @param size The size of the building.
 * @param owner Reference to the citizen who owns the building.
 * @param type The type of the building (e.g., residential, commercial).
 */
Building::Building(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type)
    : name(name), cost(cost), location(location), resources(resources), size(size), owner(&owner), type(type) {}

/**
 * @brief Destructor for the Building class.
 * Cleans up resources associated with the building.
 */
Building::~Building() {
    delete resources;
}

/**
 * @brief Processes the payment for the building.
 *
 * @return An integer indicating the payment amount; returns 0 by default.
 */
int Building::pay() {
    return 0;
}

/**
 * @brief Pays taxes based on the specified amount.
 *
 * @param amount The amount of taxes to be paid.
 */
void Building::payTax(int amount) {
    if(owner) {
        this->owner->payTaxes(amount);
    }
}

/**
 * @brief Gets the cost of the building.
 *
 * @return An integer representing the cost of the building.
 */
int Building::getCost() const {
    return this->cost;
}

/**
 * @brief Gets the location of the building.
 *
 * @return A string representing the location of the building.
 */
std::string Building::getLocation() const {
    return this->location;
}

/**
 * @brief Gets the size of the building.
 *
 * @return An integer representing the size of the building.
 */
int Building::getSize() const {
    return this->size;
}

/**
 * @brief Gets the type of the building.
 *
 * @return The type of the building.
 */
BuildingType Building::getType() const {
    return type;
}

/**
 * @brief Gets the details of the building.
 *
 * @return A string containing the details of the building.
 */
std::string Building::getDetails() const {
    std::string details = "";
    details += "Building Name:\t";
    details += name;
    details += "\nLocation:\t";
    return details;
}

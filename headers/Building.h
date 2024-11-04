#ifndef BUILDING_H
#define BUILDING_H

#include "Resources.h"
#include "Citizen.h"
#include <string>
#include <memory>
#include "BuildingType.h"

/**
 * @brief Forward declaration of Citizen and Resources classes.
 */
class Citizen;
class Resources;

/**
 * @class Building
 * @brief Represents a generic building with associated resources, owner, and type.
 */
class Building {
protected:
    std::string name;          /**< Name of the building */
    int cost;                  /**< Cost to construct or maintain the building */
    std::string location;      /**< Location of the building */
    Resources* resources;      /**< Pointer to the resources consumed by the building */
    int size;                  /**< Size of the building */
    Citizen* owner;            /**< Pointer to the owner of the building */
    BuildingType type;         /**< Type of building */

public:
    /**
     * @brief Constructs a new Building object.
     * @param name The name of the building.
     * @param cost The cost to construct the building.
     * @param location The location of the building.
     * @param resources Pointer to resources used by the building.
     * @param size The size of the building.
     * @param owner Reference to the building's owner.
     * @param type The type of the building.
     */
    Building(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type);

    /**
     * @brief Destroys the Building object.
     */
    virtual ~Building();

    /**
     * @brief Calculates and returns the amount to pay for building upkeep.
     * @return The payment amount.
     */
    virtual int pay();

    /**
     * @brief Pays a specified tax amount.
     * @param amount The tax amount to pay.
     */
    void payTax(int amount);

    /**
     * @brief Gets the cost of the building.
     * @return The cost.
     */
    int getCost() const;

    /**
     * @brief Gets the location of the building.
     * @return The location as a string.
     */
    std::string getLocation() const;

    /**
     * @brief Gets the size of the building.
     * @return The size.
     */
    int getSize() const;

    /**
     * @brief Gets the type of the building.
     * @return The building type.
     */
    BuildingType getType() const;

    /**
     * @brief Gets the water consumption of the building.
     * @return The water consumption.
     */
    int getWaterConsumption() const {
        return resources->getWaterConsumption();
    }

    /**
     * @brief Gets the power consumption of the building.
     * @return The power consumption.
     */
    int getPowerConsumption() const {
        return resources->getPowerConsumption();
    }

    /**
     * @brief Gets the name of the building.
     * @return The name.
     */
    std::string getName() const {
        return name;
    }

    /**
     * @brief Gets detailed information about the building.
     * @return A string with the building details.
     */
    std::string getDetails() const;
};

#endif // BUILDING_H

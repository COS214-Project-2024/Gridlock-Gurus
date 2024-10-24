#ifndef TAXAUTHORITY_H
#define TAXAUTHORITY_H

#include "BuildingCollection.h"
#include "Building.h"
#include "TaxStrategy.h"

/**
 * @brief Manages tax collection and taxation strategies in the city.
 *
 * Context participant in the Strategy Design Pattern.
 * 
 * The TaxAuthority class is responsible for overseeing tax-related functions, including
 * registering buildings, notifying citizens about taxes, and calculating tax amounts
 * based on specified strategies.
 */
class TaxAuthority {
private:
    BuildingCollection* buildings;  ///< Pointer to the collection of registered buildings.
    TaxStrategy* strategy;          ///< Pointer to the current tax strategy being used.
    int currentTaxRate;            ///< The current tax rate applicable for calculations.

public:
    /**
     * @brief Construct a new TaxAuthority object.
     *
     * Initializes the TaxAuthority with default values and prepares necessary components.
     */
    TaxAuthority();

    /**
     * @brief Destroy the TaxAuthority object.
     *
     * Cleans up resources and deletes any dynamically allocated components.
     */
    virtual ~TaxAuthority();

    /**
     * @brief Registers a building with the tax authority.
     *
     * @param building Pointer to the Building object to be registered.
     */
    void registerBuilding(Building* building);

    /**
     * @brief Notifies citizens about tax obligations.
     *
     * @param amount The amount of tax that citizens need to be notified about.
     */
    void notifyCitizens(int amount);

    /**
     * @brief Notifies buildings about their tax obligations.
     *
     * @param amount The amount of tax that buildings need to be notified about.
     */
    void notifyBuildings(int amount);

    /**
     * @brief Sets the tax strategy for the tax authority.
     *
     * @param taxStrategy Pointer to the TaxStrategy object to be set as the current strategy.
     */
    void setStrategy(TaxStrategy* taxStrategy);

    /**
     * @brief Calculates the tax for a building based on its value.
     *
     * @param value The assessed value of the building.
     * @return The calculated tax amount for the building.
     */
    int calculateBuildingTax(int value);

    /**
     * @brief Calculates the tax for a citizen based on their earnings.
     *
     * @param earnings The earnings of the citizen.
     * @return The calculated tax amount for the citizen.
     */
    int calculateCitizenTax(int earnings);

    /**
     * @brief Changes the current tax rate by a specified percentage.
     *
     * @param percentage The percentage by which to change the current tax rate.
     */
    void changeRate(int percentage);
};

#endif // TAXAUTHORITY_H
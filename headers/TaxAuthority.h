#ifndef TAXAUTHORITY_H
#define TAXAUTHORITY_H

#include <memory>
#include <vector>
#include <iostream>
#include "BuildingCollection.h"
#include "TaxStrategy.h"
#include "Citizen.h"

class Citizen;
class Building;
class BuildingCollection;

/**
 * @class TaxAuthority
 * @brief Manages the collection of taxes from citizens and buildings.
 */
class TaxAuthority {
private:
    std::unique_ptr<BuildingCollection> buildings;  ///< Collection of buildings.
    std::vector<Citizen*> citizens;                 ///< List of citizens.
    std::unique_ptr<TaxStrategy> strategy;          ///< Tax calculation strategy.
    int collectedTax;                               ///< Total collected tax amount.

public:
    /**
     * @brief Constructs a new TaxAuthority object.
     */
    TaxAuthority();

    /**
     * @brief Destroys the TaxAuthority object.
     */
    ~TaxAuthority() = default;

    /**
     * @brief Registers a building with the tax authority.
     * @param building Reference to the building to register.
     */
    void registerBuilding(Building& building);

    /**
     * @brief Registers a citizen with the tax authority.
     * @param citizen Reference to the citizen to register.
     */
    void registerCitizen(Citizen& citizen);

    /**
     * @brief Unregisters a citizen from the tax authority.
     * @param citizen Reference to the citizen to unregister.
     */
    void unregisterCitizen(Citizen& citizen);

    /**
     * @brief Collects taxes from all registered entities.
     * @return The total amount of taxes collected.
     */
    int collectTaxes();

    /**
     * @brief Sets the tax strategy for the authority.
     * @param taxStrategy Unique pointer to the new tax strategy.
     */
    void setStrategy(std::unique_ptr<TaxStrategy> taxStrategy);

    /**
     * @brief Sends tax payments to the authority.
     * @param amount The amount of tax to send.
     */
    void sendTax(int amount);

    /**
     * @brief Gets the total collected tax amount.
     * @return The collected tax.
     */
    int getCollectedTax();

    /**
     * @brief Gets the number of buildings registered.
     * @return The number of registered buildings.
     */
    int getSize();

    /**
     * @brief Gets the number of registered citizens.
     * @return The number of citizens.
     */
    int getAmountOfCitizens() const;

    /**
     * @brief Gets the water usage among registered buildings.
     * @return The total water usage.
     */
    int getWaterUsage() const;

    /**
     * @brief Gets the power usage among registered buildings.
     * @return The total power usage.
     */
    int getPowerUsage() const;

    /**
     * @brief Removes the last registered building.
     */
    void removeLastBuilding();

    /**
     * @brief Deregisters all citizens.
     */
    void deregisterAllCitizens();

    /**
     * @brief Gets the details of a specific citizen.
     * @param id The ID of the citizen.
     * @return A string containing the citizen's details.
     */
    std::string getCitizenDetails(int id);

    /**
     * @brief Gets a specific citizen by ID.
     * @param id The ID of the citizen.
     * @return Reference to the citizen.
     */
    Citizen& getCitizen(int id);

    /**
     * @brief Gets the collection of registered buildings.
     * 
     * @return A vector of pointers to the buildings.
     */
    std::vector<Building*>& getBuildings();

private:
    /**
     * @brief Notifies all registered citizens of tax collection.
     */
    void notifyCitizens();

    /**
     * @brief Notifies all registered buildings of tax collection.
     */
    void notifyBuildings();

    /**
     * @brief Calculates the tax for a building based on its value.
     * @param value The value of the building.
     * @return The calculated tax amount.
     */
    int calculateBuildingTax(int value);

    /**
     * @brief Calculates the tax for a citizen based on earnings.
     * @param earnings The earnings of the citizen.
     * @return The calculated tax amount.
     */
    int calculateCitizenTax(int earnings);
};

#endif // TAXAUTHORITY_H
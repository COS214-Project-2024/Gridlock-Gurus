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
    std::unique_ptr<BuildingCollection> buildings;  ///< Pointer to the collection of registered buildings.
    std::vector<Citizen*> citizens; ///< vector of shared_pointers to citizen objects.
    std::unique_ptr<TaxStrategy> strategy;          ///< Pointer to the current tax strategy being used.
    int collectedTax;

public:
    /**
     * @brief Construct a new TaxAuthority object.
     *
     * Initializes the TaxAuthority with default strategy and values.
     */
    TaxAuthority();

    /**
     * @brief Destroy the TaxAuthority object.
     *
     * Cleans up resources and deletes any dynamically allocated components.
     */
     ~TaxAuthority() = default;

    /**
     * @brief Registers a building with the tax authority.
     *
     * @param building Pointer to the Building object to be registered.
     */
    void registerBuilding(Building& building);

    /**
     * @brief Registers a citizen with the tax authority.
     *
     * @param citizen A shared_ptr to a citizen object.
     */
    void registerCitizen(Citizen& citizen);
  
    void unregisterCitizen(Citizen& citizen); 

    /**
     * @brief Notifies all registered members to pay taxes.
     */
    int collectTaxes();

    /**
     * @brief Sets the tax strategy for the tax authority.
     *
     * @param taxStrategy Pointer to the TaxStrategy object to be set as the current strategy.
     */
    void setStrategy(std::unique_ptr<TaxStrategy> taxStrategy);

    /**
    * @brief Recieves the tax from buildings and citizens.
    *
    * @param amount The amout being sent to the tax authority.
    */
    void sendTax(int amount);
    
    int getCollectedTax();
    
    /**
     * Gets the amount of buildings in the city registers with the tax authority.
     */
    int getSize();
    
    int getAmountOfCitizens() const {
        return citizens.size();
    }

    int getWaterUsage() const;
    int getPowerUsage() const;

    void removeLastBuilding();
    void deregisterAllCitizens() ;

private:
    /**
     * @brief Notifies citizens about tax obligations.
     * Iterates through a vector of registered citizens and notifies them to make payment.
     */
    void notifyCitizens();

    /**
     * @brief Notifies buildings about their tax obligations.
     * Iterates through the building collection and notifies them to make payment.
     */
    void notifyBuildings();

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
    

};

#endif // TAXAUTHORITY_H

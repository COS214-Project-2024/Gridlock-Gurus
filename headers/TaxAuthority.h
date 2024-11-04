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

class TaxAuthority {
private:
    std::unique_ptr<BuildingCollection> buildings;
    std::vector<Citizen*> citizens;
    std::unique_ptr<TaxStrategy> strategy;
    int collectedTax;

public:
    TaxAuthority();
     ~TaxAuthority() = default;
    void registerBuilding(Building& building);
    void registerCitizen(Citizen& citizen);
  
    void unregisterCitizen(Citizen& citizen); 

    /**
     * @brief Notifies all registered members to pay taxes.
     */
    int collectTaxes();
    void setStrategy(std::unique_ptr<TaxStrategy> taxStrategy);
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

    std::string getCitizenDetails(int id);
    Citizen& getCitizen(int id); 
    std::vector<Building*>& getBuildings();
 
private:
    void notifyCitizens();
    void notifyBuildings();
    int calculateBuildingTax(int value);
    int calculateCitizenTax(int earnings);
    

};

#endif // TAXAUTHORITY_H

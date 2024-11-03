#ifndef BUILDING_H
#define BUILDING_H

#include "Resources.h"
#include "Citizen.h"
#include <string>
#include <memory>
#include "BuildingType.h"

class Citizen;
class Resources;

class Building {
protected:
    int cost;  ///< The construction cost of the building.
    std::string location;  ///< The location of the building.
    Resources* resources;  ///< Resources used by the building.
    int size;  ///< The size of the building.
    Citizen* owner;  ///< The owner of the building.
    BuildingType name;

public:
    Building(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name);
    virtual ~Building();

    virtual int pay();
  
     /**
     * @brief Pays taxes on the building.
     * @param amount The amount of tax to be paid.
     */
    void payTax(int amount);
     int getCost() const;
     std::string getLocation() const;
     int getSize() const;
     BuildingType getName() const;
    int getWaterConsumption() const {
        return resources->getWaterConsumption();
    }

    int getPowerConsumption() const {
        return resources->getPowerConsumption();
    }
};

#endif // BUILDING_H

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
    int cost;
    std::string location;
    Resources* resources;
    int size;
    Citizen& owner;
    BuildingType name;

public:
    Building(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name);
    virtual ~Building();
     virtual std::string getDetails() const;
     virtual int pay();
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

#ifndef BUILDINGCOLLECTION_H
#define BUILDINGCOLLECTION_H
#include "Building.h"
#include "BuildingIterator.h"
#include <vector>
#include <memory>

class BuildingIterator;
class Building;

class BuildingCollection {
public:
    BuildingCollection() = default;

    ~BuildingCollection();
    void addBuilding(Building& building);
    BuildingIterator begin();
    BuildingIterator end();
    
    int getSize();

    void removeLastBuilding();

    int getCityWaterConsumption() const;

    int getCityPowerConsumption() const;

private:
    std::vector<Building*> buildings;

};

#endif // BUILDINGCOLLECTION_H

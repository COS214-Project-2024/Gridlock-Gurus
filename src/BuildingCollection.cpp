#include "BuildingCollection.h"
#include <iostream>

/**
 * @brief Adds a building to the collection.
 * @param building Reference to the Building to be added.
 */
void BuildingCollection::addBuilding(Building& building) {
    this->buildings.push_back(&building);
}

/**
 * @brief Destructor that cleans up all buildings in the collection.
 */
BuildingCollection::~BuildingCollection() {
    for (Building* building : buildings) {
            delete building;
    }
}

/**
 * @brief Returns an iterator to the beginning of the collection.
 * @return An iterator pointing to the first building.
 */
BuildingIterator BuildingCollection::begin() { 
    return BuildingIterator(buildings, 0); 
}

/**
 * @brief Returns an iterator to the end of the collection.
 * @return An iterator pointing to one past the last building.
 */
BuildingIterator BuildingCollection::end() { 
    return BuildingIterator(buildings, buildings.size()); 
}

/**
 * @brief Gets the number of buildings in the collection.
 * @return The size of the building collection.
 */
int BuildingCollection::getSize() {
return this->buildings.size();
}

/**
 * @brief Removes the last building from the collection.
 */
void BuildingCollection::removeLastBuilding() {
    if (!buildings.empty()) {
        delete buildings.back(); 
        buildings.pop_back();     
    }
}

/**
 * @brief Calculates the total water consumption of all buildings in the collection.
 * @return Total water consumption.
 */
int BuildingCollection::getCityWaterConsumption() const {
    int consumption = 0;
    for (Building* building : buildings) {
        consumption += building->getWaterConsumption();
    }

    return consumption;
}

/**
 * @brief Calculates the total power consumption of all buildings in the collection.
 * @return Total power consumption.
 */
int BuildingCollection::getCityPowerConsumption() const {
    int consumption = 0;
    for (Building* building : buildings) {
        consumption += building->getPowerConsumption();
    }

    return consumption;
}

/**
 * @brief Gets a reference to the vector of buildings.
 * @return Reference to the vector of pointers to buildings.
 */
std::vector<Building*>& BuildingCollection::getBuildings() {
    return buildings;
}


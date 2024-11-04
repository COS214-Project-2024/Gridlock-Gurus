#include "BuildingCollection.h"
#include <iostream>

void BuildingCollection::addBuilding(Building& building) {
    this->buildings.push_back(&building);
}

BuildingCollection::~BuildingCollection() {
    for (Building* building : buildings) {
            delete building;
    }
}

BuildingIterator BuildingCollection::begin() { 
    return BuildingIterator(buildings, 0); 
}

BuildingIterator BuildingCollection::end() { 
    return BuildingIterator(buildings, buildings.size()); 
}

int BuildingCollection::getSize() {
return this->buildings.size();
}

void BuildingCollection::removeLastBuilding() {
    if (!buildings.empty()) {
        delete buildings.back(); 
        buildings.pop_back();     
    }
}

int BuildingCollection::getCityWaterConsumption() const {
    int consumption = 0;
    for (Building* building : buildings) {
        consumption += building->getWaterConsumption();
    }

    return consumption;
}

int BuildingCollection::getCityPowerConsumption() const {
    int consumption = 0;
    for (Building* building : buildings) {
        consumption += building->getPowerConsumption();
    }

    return consumption;
}

std::vector<Building*>& BuildingCollection::getBuildings() {
    return buildings;
}


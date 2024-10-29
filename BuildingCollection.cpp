#include "BuildingCollection.h"
#include <iostream>
void BuildingCollection::addBuilding(std::shared_ptr<Building> building) {
    this->buildings.push_back(building);
}

BuildingIterator BuildingCollection::begin() { 
    return BuildingIterator(buildings, 0); 
}

BuildingIterator BuildingCollection::end() { 
    return BuildingIterator(buildings, buildings.size()); 
}


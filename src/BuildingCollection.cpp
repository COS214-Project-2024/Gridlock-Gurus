#include "BuildingCollection.h"
#include <iostream>
void BuildingCollection::addBuilding(Building& building) {
    this->buildings.push_back(&building);
}

BuildingCollection::~BuildingCollection() {
    for (Building* building : buildings) {
            delete building;
    }

    //buildings.clear();
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

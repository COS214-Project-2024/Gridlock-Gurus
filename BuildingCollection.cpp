#include "BuildingCollection.h"

BuildingCollection::~BuildingCollection() {
    for (Building *b: buildings) {
        delete b;
    }
}

void BuildingCollection::addBuilding(Building *b) {
    if (b == nullptr) {
        return;
    }
    buildings.push_back(b);
}

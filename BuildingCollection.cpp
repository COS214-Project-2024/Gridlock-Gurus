#include "BuildingCollection.h"
#include "Building.h"

void BuildingCollection::update(){
    for (Building *b: buildings) {
        b->update();
    }
}
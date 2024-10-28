#include "BuildingCollection.h"


void BuildingCollection::update(){
    for (Building *b: buildings) {
        b->update();
    }
}
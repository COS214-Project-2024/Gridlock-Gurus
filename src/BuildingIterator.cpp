#include "BuildingIterator.h"


Building* BuildingIterator::operator*() const { 
    return buildings.at(position); 
}

BuildingIterator& BuildingIterator::operator++() { 
    ++position; 
    return *this; 
}

bool BuildingIterator::operator!=(const BuildingIterator& other) const { 
    return position != other.position; 
}

bool BuildingIterator::operator==(const BuildingIterator& other) const { 
    return position == other.position; 
}

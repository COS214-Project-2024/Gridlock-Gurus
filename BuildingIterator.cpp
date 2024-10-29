#include "BuildingIterator.h"

using BuildingPtr = std::shared_ptr<Building>;

BuildingPtr BuildingIterator::operator*() const { 
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

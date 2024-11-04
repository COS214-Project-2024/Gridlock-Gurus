#include "BuildingIterator.h"

/**
 * @brief Dereference operator to access the current Building object.
 *
 * This operator returns a pointer to the Building object at the
 * current position of the iterator.
 *
 * @return Pointer to the Building object at the current position.
 */
Building* BuildingIterator::operator*() const { 
    return buildings.at(position); 
}

/**
 * @brief Pre-increment operator to advance the iterator to the next position.
 *
 * This operator increments the current position of the iterator and
 * returns a reference to the updated iterator.
 *
 * @return Reference to the updated BuildingIterator.
 */
BuildingIterator& BuildingIterator::operator++() { 
    ++position; 
    return *this; 
}

/**
 * @brief Inequality operator to compare two BuildingIterator objects.
 *
 * This operator checks if the current iterator is not equal to another
 * iterator based on their positions.
 *
 * @param other The other BuildingIterator to compare against.
 * @return True if the iterators are not equal; otherwise, false.
 */
bool BuildingIterator::operator!=(const BuildingIterator& other) const { 
    return position != other.position; 
}

/**
 * @brief Equality operator to compare two BuildingIterator objects.
 *
 * This operator checks if the current iterator is equal to another
 * iterator based on their positions.
 *
 * @param other The other BuildingIterator to compare against.
 * @return True if the iterators are equal; otherwise, false.
 */
bool BuildingIterator::operator==(const BuildingIterator& other) const { 
    return position == other.position; 
}

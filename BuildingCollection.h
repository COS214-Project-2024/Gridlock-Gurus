#ifndef BUILDINGCOLLECTION_H
#define BUILDINGCOLLECTION_H

#include "BuildCommand.h"
#include "BuildingIterator.h"
#include <list>

/**
 * @brief Holds a collection of buildings in the city.
 *
 * ConcreteAggregate? participant in the Iterator pattern, allowing iteration over its collection of buildings.
 */
class BuildingCollection {
private:
    std::list<Building*> buildings;  ///< The collection of buildings in the city.
    BuildingIterator* iterator;  ///< Iterator for iterating over buildings.

public:
    /**
     * @brief Constructs a new BuildingCollection object.
     */
    BuildingCollection();
    
    /**
     * @brief Destroys the BuildingCollection object.
     */
    ~BuildingCollection();

    /**
     * @brief Creates an iterator for the collection of buildings.
     * @return A pointer to a BuildingIterator object.
     */
    BuildingIterator* createIterator();
};

#endif // BUILDINGCOLLECTION_H

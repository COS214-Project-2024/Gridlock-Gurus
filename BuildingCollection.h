#ifndef BUILDINGCOLLECTION_H
#define BUILDINGCOLLECTION_H

#include "BuildCommand.h"
#include <list>

class Building;

/**
 * @brief Holds a collection of buildings in the city.
 *
 * ConcreteAggregate? participant in the Iterator pattern, allowing iteration over its collection of buildings.
 */
class BuildingCollection {
private:
    std::list<Building*> buildings;  ///< The collection of buildings in the city.

public:
    /**
     * @brief Constructs a new BuildingCollection object.
     */
    BuildingCollection();
    
    /**
     * @brief Destroys the BuildingCollection object.
     */
    virtual ~BuildingCollection();

    /**
     *@brief Adds a building to the collection
     */
    void addBuilding(Building *b);

    void update();
};

#endif // BUILDINGCOLLECTION_H

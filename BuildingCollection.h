#ifndef BUILDINGCOLLECTION_H
#define BUILDINGCOLLECTION_H

#include "Building.h"
#include "BuildingIterator.h"
#include <vector>
#include <memory>

class BuildingIterator;

/**
 * @class BuildingCollection
 * @brief A collection of buildings that supports iteration.
 *
 * This class allows buildings to be added to the collection and provides an iterator to traverse through them.
 */
class BuildingCollection {
public:
     /// Alias for a shared pointer to a Building object.
    using BuildingPtr = std::shared_ptr<Building>;

    /**
     * @brief Constructs a new BuildingCollection object.
     */
    BuildingCollection() = default;
    
    /**
     * @brief Destroys the BuildingCollection object.
     */
    ~BuildingCollection() = default;

    /**
     * @brief Adds a building to the collection.
     * @param building Shared pointer to the building to add.
     */
    void addBuilding(BuildingPtr building);

    /**
     * @brief Returns an iterator pointing to the beginning of the collection.
     * @return BuildingIterator to the beginning of the buildings collection.
     */
    BuildingIterator begin();

    /**
     * @brief Returns an iterator pointing to the end of the collection.
     * @return BuildingIterator to the end of the buildings collection.
     */
    BuildingIterator end();

private:
    std::vector<BuildingPtr> buildings;                 ///< The collection of buildings in the city.
};

#endif // BUILDINGCOLLECTION_H

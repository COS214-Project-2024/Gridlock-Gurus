#ifndef BUILDINGCOLLECTION_H
#define BUILDINGCOLLECTION_H
#include "Building.h"
#include "BuildingIterator.h"
#include <vector>
#include <memory>

/**
 * @brief Forward declaration of BuildingIterator and Building classes.
 */
class BuildingIterator;
class Building;

/**
 * @brief Manages a collection of Building objects.
 */
class BuildingCollection {
public:
    /**
     * @brief Constructs a new BuildingCollection object.
     */
    BuildingCollection() = default;

    /**
     * @brief Destroys the BuildingCollection object and cleans up resources.
     */
    ~BuildingCollection();

    /**
     * @brief Adds a Building to the collection.
     * @param building The building to be added.
     */
    void addBuilding(Building& building);

    /**
     * @brief Returns an iterator to the beginning of the collection.
     * @return BuildingIterator at the beginning.
     */
    BuildingIterator begin();

    /**
     * @brief Returns an iterator to the end of the collection.
     * @return BuildingIterator at the end.
     */
    BuildingIterator end();

    /**
     * @brief Gets the number of buildings in the collection.
     * @return The size of the collection.
     */
    int getSize();

    /**
     * @brief Removes the last building from the collection.
     */
    void removeLastBuilding();

    /**
     * @brief Calculates the total water consumption for the buildings.
     * @return Total water consumption.
     */
    int getCityWaterConsumption() const;

    /**
     * @brief Calculates the total power consumption for the buildings.
     * @return Total power consumption.
     */
    int getCityPowerConsumption() const;

    /**
     * @brief Returns a vector of all buildings in the collection.
     * @return Vector of Building pointers.
     */
    std::vector<Building*>& getBuildings();

private:
    std::vector<Building*> buildings; ///< Vector containing pointers to buildings.
};

#endif // BUILDINGCOLLECTION_H

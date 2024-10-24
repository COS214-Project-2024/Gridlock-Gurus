#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"

/**
 * @brief Factory class for creating different types of buildings.
 *
 * Creator participant in the Factory Method pattern. It defines the interface for creating buildings but defers the actual creation to subclasses.
 */
class BuildingFactory {
private:
    Building* building;  ///< A reference to the building being constructed.
    
protected:
    /**
     * @brief Creates a building of a specific type.
     * @param type The type of building to create.
     * @return Pointer to the created Building object.
     *
     * Factory Method function, which must be implemented by concrete factory subclasses.
     */
    virtual Building* createBuilding(std::string type) = 0;

public:
    /**
     * @brief Constructs a new BuildingFactory object.
     */
    BuildingFactory();

    /**
     * @brief Destroys the BuildingFactory object.
     */
    virtual ~BuildingFactory();

    /**
     * @brief Starts the construction process for a building.
     *
     * This method invokes the factory method to create a building and then begins its construction.
     */
    void startConstruction();
};

#endif // BUILDINGFACTORY_H
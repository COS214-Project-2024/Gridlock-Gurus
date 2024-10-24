#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating landmarks.
 * 
 * ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create landmarks.
 */
class LandmarkFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a new LandmarkFactory object.
     */
    LandmarkFactory();

    /**
     * @brief Destroys the LandmarkFactory object.
     */
    virtual ~LandmarkFactory();
    
    /**
     * @brief Creates a Landmark building.
     * @param type The type of Landmark building to create.
     * @return Pointer to the created Landmark building object.
     *
     * This method overrides the factory method to create a Landmark building.
     */
    Building* createBuilding(std::string type) override;
};

#endif // LANDMARKFACTORY_H

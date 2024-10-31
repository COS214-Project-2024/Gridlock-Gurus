#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"
#include "BuildingType.h"
#include "TaxAuthority.h"

/**
 * @brief Factory for creating landmarks.
 * 
 * ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create landmarks.
 */
class LandmarkFactory : public BuildingFactory {
private:
public:
    /**
     * @brief Constructs a new LandmarkFactory object.
     */
    LandmarkFactory(TaxAuthority& taxAuthority) : BuildingFactory(taxAuthority) {};

    /**
     * @brief Destroys the LandmarkFactory object.
     */
     ~LandmarkFactory() override = default;
    
    /**
     * @brief Creates a Landmark building.
     * @param type The type of Landmark building to create.
     * @return Pointer to the created Landmark building object.
     *
     * This method overrides the factory method to create a Landmark building.
     */
    Building* createBuilding(BuildingType type, Citizen& owner) override;
};

#endif // LANDMARKFACTORY_H

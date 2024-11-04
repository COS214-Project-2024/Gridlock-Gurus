#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include <memory>

/**
 * @class LandmarkFactory
 * @brief Factory class for creating Landmark buildings.
 */
class LandmarkFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a LandmarkFactory.
     * @param taxAuthority Shared pointer to the TaxAuthority associated with the landmarks.
     */
    LandmarkFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}

    /**
     * @brief Destructor for LandmarkFactory.
     */
    ~LandmarkFactory() override = default;
    
    /**
     * @brief Creates a Landmark building.
     * @param name The name of the Landmark building.
     * @param type The type of Landmark building to create.
     * @param owner Reference to the owner of the building.
     * @return Pointer to the created Landmark building object.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // LANDMARKFACTORY_H

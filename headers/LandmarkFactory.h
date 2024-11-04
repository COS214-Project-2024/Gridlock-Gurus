#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include <memory>


class LandmarkFactory : public BuildingFactory {
public:
    LandmarkFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}

     ~LandmarkFactory() override = default;
    
    /**
     * @brief Creates a Landmark building.
     * @param type The type of Landmark building to create.
     * @return Pointer to the created Landmark building object.
     *
     * This method overrides the factory method to create a Landmark building.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // LANDMARKFACTORY_H

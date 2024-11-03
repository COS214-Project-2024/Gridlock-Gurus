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

    Building* createBuilding(BuildingType type, Citizen& owner) override;
};

#endif // LANDMARKFACTORY_H

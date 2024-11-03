#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include <memory>
#include "BuildingFactory.h"
#include "BuildingType.h"
#include "TaxAuthority.h"

class CommercialFactory : public BuildingFactory {

public:
    CommercialFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}

     ~CommercialFactory() override = default;

     Building* createBuilding(BuildingType type, Citizen& owner) override;
};

#endif // COMMERCIALFACTORY_H

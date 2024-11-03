#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingType.h"
#include "BuildingFactory.h"
#include "TaxAuthority.h"
#include <memory>
#include <string>

class ResidentialFactory : public BuildingFactory {
public:
    ResidentialFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}
    ~ResidentialFactory() override = default;
    Building* createBuilding(BuildingType type, Citizen& owner) override;
};

#endif // RESIDENTIALFACTORY_H

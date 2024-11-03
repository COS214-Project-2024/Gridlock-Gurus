#ifndef FACTORYFACTORY_H
#define FACTORYFACTORY_H

#include "BuildingFactory.h"
#include "TaxAuthority.h"
#include "BuildingType.h"
#include <memory>

class FactoryFactory : public BuildingFactory {
public:
    FactoryFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}
    ~FactoryFactory() override = default;
    Building* createBuilding(BuildingType type, Citizen& owner) override;
};

#endif // FACTORYFACTORY_H


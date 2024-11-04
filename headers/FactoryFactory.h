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
    
    /**
     * @brief Creates a Factory building.
     * @param type The type of Factory building to create.
     * @return Pointer to the created Factory building object.
     *
     * This method overrides the factory method to create a Factory building.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // FACTORYFACTORY_H


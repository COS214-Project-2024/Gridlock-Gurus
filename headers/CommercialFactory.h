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
    
    /**
     * @brief Creates a commercial building.
     * @param type The type of commercial building to create.
     * @return Pointer to the created commercial building object.
     *
     * This method overrides the factory method to create a commercial building.
     */
     Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // COMMERCIALFACTORY_H

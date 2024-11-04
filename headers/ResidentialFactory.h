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

    /**
     * @brief Creates a residential building.
     * @param type The type of residential building to create.
     * @return Pointer to the created Residential building object.
     *
     * This method overrides the factory method to create a residential building.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // RESIDENTIALFACTORY_H

#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingType.h"
#include "BuildingFactory.h"
#include "TaxAuthority.h"
#include <memory>
#include <string>

/**
 * @class ResidentialFactory
 * @brief Factory for creating residential buildings.
 */
class ResidentialFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a new ResidentialFactory object.
     * @param taxAuthority Shared pointer to the tax authority.
     */
    ResidentialFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}

    /**
     * @brief Destroys the ResidentialFactory object.
     */
    ~ResidentialFactory() override = default;

    /**
     * @brief Creates a residential building.
     * 
     * @param name The name of the building.
     * @param type The type of residential building to create.
     * @param owner Reference to the owner of the building.
     * @return Pointer to the created Residential building object.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // RESIDENTIALFACTORY_H
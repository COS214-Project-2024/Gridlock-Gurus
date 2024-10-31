#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingType.h"
#include "BuildingFactory.h"

class TaxAuthority;

/**
 * @brief Factory for creating residential buildings.
 *
 * ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create residential buildings.
 */
class ResidentialFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a new ResidentialFactory object.
     */
    ResidentialFactory(TaxAuthority* taxAuthority) : BuildingFactory(taxAuthority) {};

    /**
     * @brief Destroys the ResidentialFactory object.
     */
    ~ResidentialFactory() override = default;

    /**
     * @brief Creates a residential building.
     * @param type The type of residential building to create.
     * @return Pointer to the created Residential building object.
     *
     * This method overrides the factory method to create a residential building.
     */
    Building* createBuilding(BuildingType type, Citizen& owner) override;
};

#endif // RESIDENTIALFACTORY_H

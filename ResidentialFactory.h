#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating residential buildings.
 *
 * ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create residential buildings.
 */
class ResidentialFactory : public BuildingFactory {
private:
    TaxAuthority* tax;
public:
    /**
     * @brief Constructs a new ResidentialFactory object.
     */
    ResidentialFactory(TaxAuthority* taxAuthority);

    /**
     * @brief Destroys the ResidentialFactory object.
     */
    virtual ~ResidentialFactory() = default;

    /**
     * @brief Creates a residential building.
     * @param type The type of residential building to create.
     * @return Pointer to the created Residential building object.
     *
     * This method overrides the factory method to create a residential building.
     */
    Building* createBuilding(string type, Citizen* owner) override;
};

#endif // RESIDENTIALFACTORY_H
#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating commercial buildings.
 * 
 *  ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create commercial buildings.
 */
class CommercialFactory : public BuildingFactory {
private:
 TaxAuthority* tax;
public:
    /**
     * @brief Constructs a new CommercialFactory object.
     */
    CommercialFactory(TaxAuthority* taxAuthority);

    /**
     * @brief Destroys the CommercialFactory object.
     */
    virtual ~CommercialFactory();
    
    /**
     * @brief Creates a commercial building.
     * @param type The type of commercial building to create.
     * @return Pointer to the created commercial building object.
     *
     * This method overrides the factory method to create a commercial building.
     */
    Building* createBuilding(string type, Citizen* owner) override;
};

#endif // COMMERCIALFACTORY_H

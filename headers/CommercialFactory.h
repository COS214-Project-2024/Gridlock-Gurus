#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include <memory>
#include "BuildingFactory.h"

/**
 * @brief Factory for creating commercial buildings.
 * 
 *  ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create commercial buildings.
 */
class CommercialFactory : public BuildingFactory {
private:
    std::shared_ptr<TaxAuthority> tax;

public:
    /**
     * @brief Constructs a new CommercialFactory object.
     */
    CommercialFactory(std::shared_ptr<TaxAuthority> taxAuthority);

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
    Building* createBuilding(std::string type, Citizen* owner) override;
};

#endif // COMMERCIALFACTORY_H

#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating service buildings.
 * 
 * ConcreteCreator participant in the Factory Method pattern. It implements the factory method to create service buildings.
 */
class ServiceFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a new ServiceFactory object.
     */
    ServiceFactory();

    /**
     * @brief Destroys the ServiceFactory object.
     */
    virtual ~ServiceFactory();
    
    /**
     * @brief Creates a service building.
     * @param type The type of service building to create.
     * @return Pointer to the created service building object.
     *
     * This method overrides the factory method to create a service building.
     */
    Building* createBuilding(std::string type) override;
};

#endif // SERVICEFACTORY_H

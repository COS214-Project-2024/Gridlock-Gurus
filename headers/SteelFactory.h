#ifndef STEELFACTORY_H
#define STEELFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"

#include <vector>
#include <string>

/**
 * @brief Represents a steel factory.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Factory class and represents a factory that produces steel.
 */
class SteelFactory : public Factory {
public:
    /**
     * @brief Constructs a new SteelFactory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    SteelFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name, int productionRate, int max) 
    : Factory(cost, location, resources,size,owner,name,productionRate,max) {};

    /**
     * @brief Destroys the SteelFactory object.
     */
    ~SteelFactory() override = default;

    /**
     * @brief Gets details about the steel factory.
     * @return A string containing details about the steel factory.
     */
    std::string getDetails() const override;

    /**
     * @brief Produces steel in the factory.
     */
    int produceResource() override;

    /**
     * @brief Pays an employee working at the steel factory.
     * @param employee Pointer to the employee.
     */
     int pay() override;

};

#endif // STEELFACTORY_H

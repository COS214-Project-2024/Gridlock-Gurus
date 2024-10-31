#ifndef BRICKFACTORY_H
#define BRICKFACTORY_H

#include "Factory.h"
#include "Building.h"
#include "BuildingType.h"

#include <vector>
#include <size>

/**
 * @brief Represents a brick manufacturing factory.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Factory class and represents a factory that produces bricks.
 */
class BrickFactory : public Factory {
public:
    /**
     * @brief Constructs a new BrickFactory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    BrickFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, TaxAuthority& taxAuthority,BuildingType name, int productionRate, int max);

    /**
     * @brief Destroys the BrickFactory object.
     */
     ~BrickFactory() override = default;

    /**
     * @brief Gets details about the brick factory.
     * @return A string containing details about the brick factory.
     */
    std::string getDetails() const override;

    /**
     * @brief Pays taxes for the brick factory.
     */
    // void payTax(int amount) override;

    /**
     * @brief Produces bricks in the factory.
     */
    void produceResource() override;

    /**
     * @brief Pays an employee working at the brick factory.
     * @param employee Pointer to the employee.
     */
    int pay() override;
};

#endif // BRICKFACTORY_H

#ifndef WOODFACTORY_H
#define WOODFACTORY_H

#include "Factory.h"
#include <list>

/**
 * @brief Represents a wood processing factory.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Factory class and represents a factory that processes wood.
 */
class WoodFactory : public Factory {
private:
    list<Citizen*> employees;  ///< List of employees working at the wood factory.
    string name;
public:
    /**
     * @brief Constructs a new WoodFactory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    WoodFactory(int cost, string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority, int productionRate, int max);

    /**
     * @brief Destroys the WoodFactory object.
     */
    virtual ~WoodFactory() = default;

    /**
     * @brief Gets details about the wood factory.
     * @return A string containing details about the wood factory.
     */
    string getDetails() override;

    /**
     * @brief Pays taxes for the wood factory.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the factory's owner.
     */
    void payTax(int amount, Citizen* owner) override;

    /**
     * @brief Produces wood in the factory.
     */
    void produceResource() override;

    /**
     * @brief Pays an employee working at the wood factory.
     * @param employee Pointer to the employee.
     */
     int payEmployee(Citizen* employee);
     void employ(Citizen* employee);
     void fire(Citizen* employee);
     void retire(Citizen* employee);
};

#endif // WOODFACTORY_H
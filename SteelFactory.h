#ifndef STEELFACTORY_H
#define STEELFACTORY_H

#include "Factory.h"
#include <list>

/**
 * @brief Represents a steel factory.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Factory class and represents a factory that produces steel.
 */
class SteelFactory : public Factory {
private:
    std::list<Citizen*> employees;  ///< List of employees working at the steel factory.

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
    SteelFactory(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority);

    /**
     * @brief Destroys the SteelFactory object.
     */
    virtual ~SteelFactory();

    /**
     * @brief Gets details about the steel factory.
     * @return A string containing details about the steel factory.
     */
    std::string getDetails() override;

    /**
     * @brief Pays taxes for the steel factory.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the factory's owner.
     */
    void payTax(int amount, Citizen* owner) override;

    /**
     * @brief Produces steel in the factory.
     */
    void produceResource() override;

    /**
     * @brief Pays an employee working at the steel factory.
     * @param employee Pointer to the employee.
     */
    void payEmployee(Citizen* employee);
};

#endif // STEELFACTORY_H
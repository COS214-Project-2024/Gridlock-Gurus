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
    string name;
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
    SteelFactory(int cost, string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority, int productionRate, int max);

    /**
     * @brief Destroys the SteelFactory object.
     */
    virtual ~SteelFactory() = default;

    /**
     * @brief Gets details about the steel factory.
     * @return A string containing details about the steel factory.
     */
    string getDetails() override;

    /**
     * @brief Pays taxes for the steel factory.
     */
    void payTax() override;

    /**
     * @brief Produces steel in the factory.
     */
    void produceResource() override;

    /**
     * @brief Pays an employee working at the steel factory.
     * @param employee Pointer to the employee.
     */
     int pay(Citizen* employee) override;
     void employ(Citizen* employee) override;
     void fire(Citizen* employee) override;
     void retire(Citizen* employee) override;
     void update() override;
};

#endif // STEELFACTORY_H
#ifndef SERVICE_H
#define SERVICE_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <iostream>

/**
 * @brief Represents a service building (e.g., hospital, police station).
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and serves as a base for specific types of service buildings, providing a common interface for tax payment and services.
 */
class Service : public Building {
protected:
     std::string type;
     double benefits;
public:
    /**
     * @brief Constructs a new Service building.
     * @param cost The construction cost of the service building.
     * @param location The location of the service building.
     * @param resources Pointer to the resources the building uses.
     * @param size The size of the service building.
     * @param owner Pointer to the owner of the service building.
     * @param taxAuthority Pointer to the tax authority associated with the service building.
     */
    Service(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority);

    /**
     * @brief Destroys the Service building.
     */
    virtual ~Service() = default;

    /**
     * @brief Gets details about the service building.
     * @return A string containing details about the service building.
     */
    virtual std::string getDetails() = 0;  ///< Pure virtual function

    /**
     * @brief Pays taxes for the service building.
     */
    virtual void payTax(int amount) = 0;  ///< Pure virtual function

    /**
     * @brief Produces resources in the service building.
     */
    virtual void employ(Citizen* employee) = 0;
    virtual int pay(Citizen* employee) = 0;
    virtual void fire(Citizen* employee) = 0;
    virtual void retire(Citizen* employee) = 0;
    virtual void update() = 0;
};

#endif // SERVICE_H
#ifndef SERVICE_H
#define SERVICE_H

#include "Building.h"

/**
 * @brief Represents a service building (e.g., hospital, police station).
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and serves as a base for specific types of service buildings, providing a common interface for tax payment and services.
 */
class Service : public Building {
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
    virtual ~Service();

    /**
     * @brief Gets details about the service building.
     * @return A string containing details about the service building.
     */
    virtual std::string getDetails() = 0;  ///< Pure virtual function

    /**
     * @brief Pays taxes for the service building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
    virtual void payTax(int amount, Citizen* owner) = 0;  ///< Pure virtual function

    /**
     * @brief Produces resources in the service building.
     */
    virtual void produceResource() = 0;  ///< Pure virtual function
};

#endif // SERVICE_H
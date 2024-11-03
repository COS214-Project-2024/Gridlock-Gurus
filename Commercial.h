#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

/**
 * @brief Represents a commercial building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and adds functionality specific to commercial buildings, including the ability to generate money.
 */
class Commercial : public Building {
private:
    int productionRate;  ///< The rate at which the commercial building generates money.

public:
    /**
     * @brief Constructs a new Commercial building.
     * @param cost The construction cost of the building.
     * @param location The location of the building.
     * @param resources Pointer to the resources the building consumes.
     * @param size The size of the building.
     * @param owner Pointer to the owner of the building.
     * @param taxAuthority Pointer to the tax authority associated with the building.
     */
    Commercial(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority);  ///< Constructor

    /**
     * @brief Destroys the Commercial building.
     */
    virtual ~Commercial();  ///< Destructor

    /**
     * @brief Pays taxes for the commercial building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
    void payTax(int amount, Citizen* owner) override;

    /**
     * @brief Gets details about the commercial building.
     * @return A string containing details about the commercial building.
     */
    std::string getDetails() override;

    /**
     * @brief Generates money in the commercial building.
     */
    void produceMoney();
};

#endif // COMMERCIAL_H 
#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "BuidingType.h"

class TaxAuthority;

/**
 * @brief Represents a commercial building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and adds functionality specific to commercial buildings, including the ability to generate money.
 */
class Commercial : public Building {
private:
    int productionRate;  
    int maxEmployees;
    std::vector<Citizen*> employees;  

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
    Commercial(int cost, std::string& location, Resources* resources, int size, Citizen& owner, TaxAuthority& taxAuthority, int max, int rate); 

    /**
     * @brief Destroys the Commercial building.
     */
    ~Commercial() override = default;

    std::string getDetails() const override;

    /**
     * @brief Generates money in the commercial building.
     */
    void produceMoney();

    void employ(Citizen& employee);

    int pay() override;

    void fire(Citizen& employee);

    void retire(Citizen& employee);

    int getNumberOfEmployees() {
        return this->employees.size();
    }

    int getProductionRate() {
        return this->productionRate;
    }

    int getMaxEmployees() {
        return this->maxEmployees;
    }

};

#endif // COMMERCIAL_H

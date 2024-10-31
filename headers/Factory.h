#ifndef FACTORY_H
#define FACTORY_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>
#include <vector>


/**
 * @brief Represents an industrial factory building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and adds functionality specific to factories, including production of resources.
 */
class Factory : public Building {
protected:
    int maxEmployees;  ///< Number of employees working in the factory.
    int productionRate;  ///< The rate at which resources are produced by the factory.
    std::vector<Citizen*> employees;

public:
    /**
     * @brief Constructs a new Factory object.
     * @param cost The construction cost of the factory.
     * @param location The location of the factory.
     * @param resources Pointer to the resources the factory consumes.
     * @param size The size of the factory.
     * @param owner Pointer to the factory's owner.
     * @param taxAuthority Pointer to the tax authority associated with the factory.
     */
    Factory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name, int productionRate, int max) 
    : Building(cost,location,resources,size,owner,name) {
        this->productionRate = productionRate;
        this->maxEmployees = max;
    };

    /**
     * @brief Destroys the Factory object.
     */
    virtual ~Factory() = default;

    /**
     * @brief Produces resources in the factory.
     *
     * This is an abstract method that must be implemented by concrete factory subclasses.
     */
    virtual int produceResource() = 0;
    void employ(Citizen& employee);
    void fire(Citizen& employee) ;
    void retire(Citizen& employee);
};

#endif // FACTORY_H

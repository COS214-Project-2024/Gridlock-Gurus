#ifndef FACTORY_H
#define FACTORY_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>
#include <vector>

/**
 * @class Factory
 * @brief Abstract class representing a factory building.
 */
class Factory : public Building {
protected:
    int maxEmployees;           ///< Maximum number of employees in the factory
    int productionRate;         ///< Rate at which resources are produced
    std::vector<int> employees; ///< Vector list of employees

public:
    /**
     * @brief Constructor for Factory.
     * @param name The name of the factory.
     * @param cost The cost of the factory.
     * @param location The location of the factory.
     * @param resources A pointer to the resources available to the factory.
     * @param size The size of the factory.
     * @param owner The owner of the factory.
     * @param type The type of building.
     * @param productionRate The production rate of the factory.
     * @param max The maximum number of employees allowed in the factory.
     */
    Factory(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) 
    : Building(name,cost,location,resources,size,owner,type) {
        this->productionRate = productionRate;
        this->maxEmployees = max;
    };

    /** 
     * @brief Default destructor for Factory class.
     */
    virtual ~Factory() = default;

    /**
     * @brief Produce resources (pure virtual function).
     * @return The amount of resources produced.
     */
    virtual int produceResource() = 0;

    /**
     * @brief Employ a citizen in the factory.
     * @param employee The citizen to be employed.
     */
    void employ(Citizen& employee);

    /**
     * @brief Fire a citizen from the factory.
     * @param employee The citizen to be fired.
     */
    void fire(Citizen& employee);

    /**
     * @brief Retire a citizen from the factory.
     * @param employee The citizen to be retired.
     */
    void retire(Citizen& employee);

    /**
     * @brief Get the current number of employees in the factory.
     * @return The number of employees.
     */
    int getNumberOfEmployees() {
        return employees.size();
    }

    /**
     * @brief Get the maximum number of employees allowed in the factory.
     * @return The maximum number of employees.
     */
    int getMaxEmployees() {
        return maxEmployees;
    }

    /**
     * @brief Check if the factory is full.
     * @return True if the maximum number of employees is reached; otherwise false.
     */
    bool isFull() {
        return maxEmployees <= employees.size();
    }

    /**
     * @brief Get the list of employees.
     * @return A reference to the vector of employees.
     */
    std::vector<int>& getEmployees();

};

#endif // FACTORY_H

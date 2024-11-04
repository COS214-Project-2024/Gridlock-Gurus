#ifndef FACTORY_H
#define FACTORY_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>
#include <vector>



class Factory : public Building {
protected:
    int maxEmployees;  ///< Number of employees working in the factory.
    int productionRate;  ///< The rate at which resources are produced by the factory.
    std::vector<int> employees;

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
    Factory(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int productionRate, int max) 
    : Building(name,cost,location,resources,size,owner,type) {
        this->productionRate = productionRate;
        this->maxEmployees = max;
    };

    virtual ~Factory() = default;

    virtual int produceResource() = 0;
    void employ(Citizen& employee);
    void fire(Citizen& employee) ;
    void retire(Citizen& employee);

    int getNumberOfEmployees() {
        return employees.size();
    }

    int getMaxEmployees() {
        return maxEmployees;
    }

    bool isFull() {
        return maxEmployees <= employees.size();
    }

    std::vector<int>& getEmployees();

};

#endif // FACTORY_H

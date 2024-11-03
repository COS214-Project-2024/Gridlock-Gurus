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
    Factory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name, int productionRate, int max) 
    : Building(cost,location,resources,size,owner,name) {
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
};

#endif // FACTORY_H

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
    int maxEmployees;
    int productionRate;
    std::vector<int> employees;

public:
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

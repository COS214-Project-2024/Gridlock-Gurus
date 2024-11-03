#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "BuildingType.h"


class Commercial : public Building {
private:
    int productionRate;  
    int maxEmployees;
    std::vector<Citizen*> employees;  

public:
    Commercial(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name,int max, int rate); 

    ~Commercial() override = default;

    int produceMoney();

    void employ(Citizen& employee);

    int pay() override;

    void fire(Citizen& employee);

    void retire(Citizen& employee);

    int getNumberOfEmployees(); 

    int getProductionRate();

    int getMaxEmployees(); 

    bool isFull() {
        return maxEmployees <= employees.size();
    }
};

#endif // COMMERCIAL_H

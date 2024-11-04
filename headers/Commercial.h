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
    std::vector<int> employees;  

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
    Commercial(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type,int max, int rate); 

    ~Commercial() override = default;
    /**
     * @brief Generates money in the commercial building.
     */
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

    std::vector<int>& getEmployees();

};


#endif // COMMERCIAL_H

#ifndef SERVICE_H
#define SERVICE_H

#include "Building.h"
#include "BuildingType.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>


class Service : public Building {
protected:
    std::vector<int> employees;
    double benefits;
    int maxEmployees;
    int id;
public:
    Service(int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType name,int id);

    /**
     * @brief Destroys the Service building.
     */
    virtual ~Service() {
        employees.clear();
    }

    /**
     * @brief Produces resources in the service building.
     */
    void employ(Citizen& employee);
    void fire(Citizen& employee);
    void retire(Citizen& employee);

    int getNumberOfEmployees() {
        return this->employees.size();
    }

    int getMaxEmployees() {
        return maxEmployees;
    }

    int getId() {
        return id;
    }

    bool isFull() {
        return maxEmployees <= employees.size();
    }

};

#endif // SERVICE_H

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
    /**
     * @brief Constructs a new Service building.
     * @param cost The construction cost of the service building.
     * @param location The location of the service building.
     * @param resources Pointer to the resources the building uses.
     * @param size The size of the service building.
     * @param owner Pointer to the owner of the service building.
     */
    Service(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType type,int id);

    /**
     * @brief Destroys the Service building.
     */
    virtual ~Service() = default;
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

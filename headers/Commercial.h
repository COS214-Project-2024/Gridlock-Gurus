#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "BuildingType.h"

/**
 * @brief Class representing a commercial building.
 */
class Commercial : public Building {
private:
    int productionRate;    ///< Rate of money production.
    int maxEmployees;      ///< Maximum number of employees allowed.
    std::vector<int> employees; ///< List of employees working in the building.

public:
    /**
     * @brief Constructs a Commercial building with specified parameters.
     * @param name Name of the building.
     * @param cost Cost of the building.
     * @param location Location of the building.
     * @param resources Pointer to resources associated with the building.
     * @param size Size of the building.
     * @param owner Owner of the building.
     * @param type Type of the building.
     * @param max Maximum number of employees.
     * @param rate Rate of production.
     */
    Commercial(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int max, int rate);

    /**
     * @brief Default destructor.
     */
    ~Commercial() override = default;

    /**
     * @brief Produces money based on the building's production rate.
     * @return The amount of money produced.
     */
    int produceMoney();

    /**
     * @brief Employs a citizen in the building.
     * @param employee The citizen to employ.
     */
    void employ(Citizen& employee);

    /**
     * @brief Pays salaries to employees.
     * @return The total amount paid.
     */
    int pay() override;

    /**
     * @brief Fires an employee from the building.
     * @param employee The citizen to be fired.
     */
    void fire(Citizen& employee);

    /**
     * @brief Retires an employee.
     * @param employee The citizen to retire.
     */
    void retire(Citizen& employee);

    /**
     * @brief Gets the number of employees.
     * @return The number of employees in the building.
     */
    int getNumberOfEmployees();

    /**
     * @brief Gets the building's production rate.
     * @return The production rate.
     */
    int getProductionRate();

    /**
     * @brief Gets the maximum number of employees allowed.
     * @return The maximum number of employees.
     */
    int getMaxEmployees();

    /**
     * @brief Checks if the building has reached its employee capacity.
     * @return True if full, otherwise false.
     */
    bool isFull() {
        return maxEmployees <= employees.size();
    }

    /**
     * @brief Gets the list of employees working in the building.
     * @return Reference to the vector of employees.
     */
    std::vector<int>& getEmployees();
};

#endif // COMMERCIAL_H

#include "Commercial.h"

/**
 * @brief Constructs a Commercial building with the specified parameters.
 *
 * @param name The name of the building.
 * @param cost The cost of the building.
 * @param location The location of the building.
 * @param resources Pointer to the resources associated with the building.
 * @param size The size of the building.
 * @param owner The citizen who owns the building.
 * @param type The type of the building (Commercial).
 * @param max The maximum number of employees allowed.
 * @param rate The production rate of the building.
 */
Commercial::Commercial(const std::string& name,int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType type, int max, int rate) : Building(name,cost, location, resources, size, owner , type) {
    this->maxEmployees = max;
    this->productionRate = rate;
}

/**
 * @brief Produces money for the commercial building.
 *
 * @return The amount of money produced.
 */
int Commercial::produceMoney() {
    return 100;
}

/**
 * @brief Employs a citizen in the commercial building.
 *
 * @param employee The citizen to be employed.
 *
 * If the employee is not already employed and the maximum number of employees
 * has not been reached, the employee is added to the building's employee list.
 */
void Commercial::employ(Citizen& employee) {
    if(!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(employee.getId());
        employee.setWork(*this);
    }

}

/**
 * @brief Pays a fixed amount to the commercial building.
 *
 * @return The payment amount.
 */
int Commercial::pay() {
    return 3700;
}

/**
 * @brief Fires an employee from the commercial building.
 *
 * @param employee The citizen to be fired.
 *
 * If the employee is found in the list, they are removed, and their employment status is updated.
 */
void Commercial::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.fired();
    }   
}

/**
 * @brief Retires an employee from the commercial building.
 *
 * @param employee The citizen to be retired.
 *
 * If the employee is found in the list, they are removed and their status is updated to retired.
 */
void Commercial::retire(Citizen& employee) {
    auto it = find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}

/**
 * @brief Retrieves the production rate of the commercial building.
 *
 * @return The production rate.
 */
int Commercial::getProductionRate() {
    return productionRate;
}

/**
 * @brief Retrieves the current number of employees in the commercial building.
 *
 * @return The number of employees.
 */
int Commercial::getNumberOfEmployees() {
    return employees.size();
}

/**
 * @brief Retrieves the maximum number of employees allowed in the commercial building.
 *
 * @return The maximum number of employees.
 */
int Commercial::getMaxEmployees() {
    return maxEmployees;
}

/**
 * @brief Retrieves the list of employees currently employed in the commercial building.
 *
 * @return A reference to the vector of employee IDs.
 */
std::vector<int>& Commercial::getEmployees() {
    return employees;
}

#include "Factory.h"
#include "Building.h"

/**
 * @brief Fires an employee from the factory.
 *
 * Removes the specified employee from the factory's employee list and
 * updates the employee's status to "fired".
 *
 * @param employee The Citizen to be fired.
 */
void Factory::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.fired();
    }   
}

/**
 * @brief Retires an employee from the factory.
 *
 * Removes the specified employee from the factory's employee list and
 * updates the employee's status to "retired".
 *
 * @param employee The Citizen to be retired.
 */
void Factory::retire(Citizen& employee) {
    auto it = find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}


/**
 * @brief Employs a citizen at the factory.
 *
 * Adds the specified employee to the factory's employee list if they are
 * not already employed and if the factory has not reached its maximum
 * number of employees.
 *
 * @param employee The Citizen to be employed.
 */
void Factory::employ(Citizen& employee) {
    if(!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(employee.getId());
        employee.setWork(*this);
    }
}

/**
 * @brief Retrieves the list of employees in the factory.
 *
 * @return A reference to the vector containing the IDs of the employees.
 */
std::vector<int>& Factory::getEmployees() {
    return employees;
}

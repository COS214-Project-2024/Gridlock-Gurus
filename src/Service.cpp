#include "Service.h"

/**
 * @brief Constructs a Service building with specified parameters.
 *
 * @param name The name of the service.
 * @param cost The construction cost.
 * @param location The location of the service.
 * @param resources Pointer to the building's resources.
 * @param size The building's size.
 * @param owner The owner of the building.
 * @param type The type of the building.
 * @param id The unique ID of the service.
 */
Service::Service(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner,BuildingType type,int id) : Building(name,cost, location, resources, size, owner,type) {
    this->id = id;
    this->maxEmployees = 30;
    this->benefits = 0.5;
}

/**
 * @brief Employs a citizen if there is capacity and they are unemployed.
 *
 * @param employee The citizen to employ.
 */
void Service::employ(Citizen& employee) {
    if (!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(employee.getId());
    }
}

/**
 * @brief Fires an employee if they are currently employed.
 *
 * @param employee The citizen to fire.
 */
void Service::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employee.fired();
        employees.erase(it);
    }
}

/**
 * @brief Retires an employee and relocates them to the countryside.
 *
 * @param employee The citizen to retire.
 */
void Service::retire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}

#include "Service.h"

Service::Service(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner,BuildingType type,int id) : Building(name,cost, location, resources, size, owner,type) {
    this->id = id;
    this->maxEmployees = 30;
    this->benefits = 0.5;
}

void Service::employ(Citizen& employee) {
    if (!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(employee.getId());
    }
}

void Service::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employee.fired();
        employees.erase(it);
    }
}

void Service::retire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}

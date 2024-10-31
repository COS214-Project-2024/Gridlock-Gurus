#include "SteelFactory.h"

SteelFactory::SteelFactory(int cost, std::string& location, Resources *resources, int size, Citizen& owner, TaxAuthority& taxAuthority,BuildingType name, int productionRate, int max) : Factory(cost, location, resources, size, owner, taxAuthority,name, productionRate, max){}

std::string SteelFactory::getDetails() {
    std::string details =  "Steel factory: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void SteelFactory::produceResource() {
    //impliment
}

void SteelFactory::employ(Citizen &employee) {
    if(!employee.getEmploymentStatus()&& employees.size() < maxEmployees) {
        employees.push_back(&employee);
    } 
}

int SteelFactory::pay() {
/*    auto it = find(employees.begin(), employees.end(), &employee);
    if(it != employees.end()) {
        double salary;
        int amount = 163;
        //benefits are affected by the state of education
        std::cout<< employee->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return amount;
    } else {
        std::cout << employee->getName() << "? Who the heck are you? You're not a doctor!\n";
    }*/
    return 163;
}

void SteelFactory::fire(Citizen &employee) {
    auto it = find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employees.erase(it);
        //std::cout<< employee->getName() << " was fired from their job.\n";
        employee.fired();
    } 
}

void SteelFactory::retire(Citizen& employee) {
    auto it = find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employees.erase(it);
        //std::cout<< employee->getName() << " retired from their job.\n";
        employee.retireToCountryside();
    } 
}

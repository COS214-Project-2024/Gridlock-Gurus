#include "BrickFactory.h"

BrickFactory::BrickFactory(int cost, std::string& location, Resources *resources, int size, Citizen *owner, TaxAuthority* taxAuthority, int productionRate, int max) : Factory(cost, location, resources, size, owner, taxAuthority, productionRate, max){
    name = "BrickFactory";
}

std::string BrickFactory::getDetails() {
    std::string details =  "Brick factory: \n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(numOfEmployees) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void BrickFactory::produceResource() {
    //impliment
}

void BrickFactory::employ(Citizen *employee) {
    if(!employee->getEmploymentStatus()) {
        if(numOfEmployees+1 <= maxEmployees) {
            employees.push_back(employee);
            numOfEmployees++;
        } 
    } 
}

int BrickFactory::pay() {
    return 163;
}

void BrickFactory::fire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);

    if(it != employees.end()) {
        employee->fired();
        employees.erase(it);
        numOfEmployees--;
    }
}


void BrickFactory::retire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);

    if(it != employees.end()) {
        employees.erase(it);
        employee->retireToCountryside();
        numOfEmployees--;
    }
}

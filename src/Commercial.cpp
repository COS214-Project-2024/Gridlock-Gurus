#include "Commercial.h"

Commercial::Commercial(int cost, std::string& location, Resources *resources, int size, Citizen *owner,TaxAuthority* taxAuthority, int max, int rate) : Building(cost, location, resources, size, owner, taxAuthority) {
    this->maxEmployees = max;
    this->productionRate = rate;
    this->numEmployees = 0;
}

std::string Commercial::getDetails() {
    std::string details =  "Shop: \n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(numEmployees) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void Commercial::produceMoney() {
    //implement
}

void Commercial::employ(Citizen *employee) {
    if(!employee->getEmploymentStatus() != true) {
        if(numEmployees+1 <= maxEmployees) {
            employees.push_back(employee);
            numEmployees++;
        }     
    }
}

int Commercial::pay() {
    return 3700;
}

void Commercial::fire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);

    if(it != employees.end()) {
        employee->fired();
        employees.erase(it);
        numEmployees--;
    }
}

void Commercial::retire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);

    if(it != employees.end()) {
        employees.erase(it);
        employee->retireToCountryside();
        numEmployees--;
    }
}


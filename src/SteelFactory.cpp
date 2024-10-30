#include "SteelFactory.h"

SteelFactory::SteelFactory(int cost, std::string location, Resources *resources, int size, Citizen *owner, std::weak_ptr<TaxAuthority> taxAuthority, int productionRate, int max) : Factory(cost, location, resources, size, owner, taxAuthority, productionRate, max){
    name = "SteelFactory";
}

std::string SteelFactory::getDetails() {
    std::string details =  "Steel factory: \n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(numOfEmployees) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void SteelFactory::produceResource() {
    //impliment
}

void SteelFactory::employ(Citizen *employee) {
    if(employee->getEmploymentStatus() != true) {
        if(numOfEmployees+1 <= maxEmployees) {
            if(find(employees.begin(), employees.end(), employee) != employees.end()) {
                employees.push_back(employee);
            } else {
                std::cout<< employee->getName() << " is already employed.\n";
            }
            numOfEmployees++;
        } else {
            std::cout<< "This factory is fully staffed, " + employee->getName() + " can't apply here.\n";
        }
    } else {
        std::cout<< employee->getName() << " is already employed.\n";
    }
}

int SteelFactory::pay(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        double salary;
        int amount = 163;
        //benefits are affected by the state of education
        std::cout<< employee->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return amount;
    } else {
        std::cout << employee->getName() << "? Who the heck are you? You're not a doctor!\n";
    }
    return 0;
}

void SteelFactory::fire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        employees.erase(it);
        std::cout<< employee->getName() << " was fired from their job.\n";
        employee->fired();
        numOfEmployees--;
    } else {
        std::cout << employee->getName() << " was not found. How did they get in?\n";
    }
}


void SteelFactory::retire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        employees.erase(it);
        std::cout<< employee->getName() << " retired from their job.\n";
        employee->retireToCountryside();
        numOfEmployees--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps they were commiting tax fraud?\n";
    }
}

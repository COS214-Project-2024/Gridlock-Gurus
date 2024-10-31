#include "WoodFactory.h"

WoodFactory::WoodFactory(int cost, std::string& location, Resources& resources, int size, Citizen& owner, TaxAuthority& taxAuthority, int productionRate, int max, BuildingType name) : Factory(cost, location, resources, size, owner, taxAuthority, productionRate, max,name){}

std::string WoodFactory::getDetails() {
    std::string details =  "Wood factory: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(numOfEmployees) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void WoodFactory::produceResource() {
    //impliment
}

void WoodFactory::employ(Citizen& employee) {
    if(!employee.getEmploymentStatus()) {
        if(numOfEmployees < maxEmployees) {
            employees.push_back(&employee);
            numOfEmployees++;
        }     
    }
}

int WoodFactory::pay() {
/*    auto it = find(employees.begin(), employees.end(), employee);
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

void WoodFactory::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employees.erase(it);
        //std::cout<< employee->getName() << " was fired from their job.\n";
        employee.fired();
        numOfEmployees--;
    } else {
        //std::cout << employee->getName() << " was not found. How did they get in?\n";
    }
}


void WoodFactory::retire(Citizen& employee) {
    auto it = find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employees.erase(it);
        //std::cout<< employee->getName() << " retired from their job.\n";
        employee.retireToCountryside();
        numOfEmployees--;
    } else {
        //std::cout << employee->getName() << " was not found. Perhaps they were commiting tax fraud?\n";
    }
}

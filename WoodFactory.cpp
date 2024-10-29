#include "WoodFactory.h"

WoodFactory::WoodFactory(int cost, string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, int productionRate, int max) : Factory(cost, location, resources, size, owner, taxAuthority, productionRate, max){
    name = "WoodFactory";
}

std::string WoodFactory::getDetails() {
    string details =  "Wood factory: \n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + to_string(numOfEmployees) + "/" + to_string(maxEmployees) + "\n";
    details += "Cost: " + to_string(cost) + "\n";
    details += "Size: " + to_string(size) + "\n";
    return details;
}

void WoodFactory::payTax(int amount, Citizen *owner) {
    //implement
}

void WoodFactory::produceResource() {
    //impliment
}

void WoodFactory::employ(Citizen *employee) {
    if(employee->getEmploymentStatus() != true) {
        if(numOfEmployees+1 <= maxEmployees) {
            if(find(employees.begin(), employees.end(), employee) != employees.end()) {
                employees.push_back(employee);
            } else {
                cout<< employee->getName() << " is already employed.\n";
            }
            numOfEmployees++;
        } else {
            cout<< "This factory is fully staffed, " + employee->getName() + " can't apply here.\n";
        }
    } else {
        cout<< employee->getName() << " is already employed.\n";
    }
}

int WoodFactory::payEmployee(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        double salary;
        int amount = 163;
        //benefits are affected by the state of education
        cout<< employee->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return amount;
    } else {
        std::cout << employee->getName() << "? Who the heck are you? You're not a doctor!\n";
    }
}

void WoodFactory::fire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        employees.erase(it);
        cout<< employee->getName() << " was fired from their job.\n";
        employee->fired();
        numOfEmployees--;
    } else {
        std::cout << employee->getName() << " was not found. How did they get in?\n";
    }
}


void WoodFactory::retire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        employees.erase(it);
        cout<< employee->getName() << " retired from their job.\n";
        employee->retireToCountryside();
        numOfEmployees--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps they were commiting tax fraud?\n";
    }
}

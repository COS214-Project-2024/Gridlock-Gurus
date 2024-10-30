#include "BrickFactory.h"

BrickFactory::BrickFactory(int cost, std::string location, Resources *resources, int size, Citizen *owner, std::weak_ptr<TaxAuthority> taxAuthority, int productionRate, int max) : Factory(cost, location, resources, size, owner, taxAuthority, productionRate, max){
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
// Building taxes are implemented by Building
/*void BrickFactory::payTax(int amount) {
    owner->payTaxes(amount);
}*/

void BrickFactory::produceResource() {
    //impliment
}

void BrickFactory::employ(Citizen *employee) {
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

int BrickFactory::pay(Citizen *employee) {
    int amount = 163;
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        double salary;
        //benefits are affected by the state of education
        std::cout<< employee->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return amount;
    } else {
        std::cout << employee->getName() << "? Who the heck are you? Youdon't work here!\n";
    }
    return amount;
}

void BrickFactory::fire(Citizen *employee) {
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


void BrickFactory::retire(Citizen *employee) {
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

// void BrickFactory::update(){
//     // payTax();
// }

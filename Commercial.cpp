#include "Commercial.h"

Commercial::Commercial(int cost, std::string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, int max, int rate) : Building(cost, location, resources, size, owner, taxAuthority) {
    this->maxEmployees = max;
    this->productionRate = rate;
    this->numEmployees = 0;
}

void Commercial::payTax(int amount) {
    owner->payTaxes(amount);
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
    if(employee->getEmploymentStatus() != true) {
        if(numEmployees+1 <= maxEmployees) {
            if(find(employees.begin(), employees.end(), employee) != employees.end()) {
                employees.push_back(employee);
            } else {
                std::cout<< employee->getName() << " is already employed.\n";
            }
            numEmployees++;
        } else {
            std::cout<< "This shop is fully staffed, " + employee->getName() + " can't apply here.\n";
        }
    } else {
        std::cout<< employee->getName() << " is already employed.\n";
    }
}

int Commercial::pay(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        int amount = 3700;
        std::cout<< employee->getName() << " was paid their salary. R" << amount << " was paid into their account\n";
        return amount;
    } else {
        std::cout << employee->getName() << "? Who the heck are you? You're not a doctor!\n";
    }
}

void Commercial::fire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        employees.erase(it);
        std::cout<< employee->getName() << " was fired from their job. Their patients breathe a sigh of relief.\n";
        employee->fired();
        numEmployees--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps we should call security?\n";
    }
}

void Commercial::retire(Citizen *employee) {
    auto it = find(employees.begin(), employees.end(), employee);
    if(it != employees.end()) {
        employees.erase(it);
        std::cout<< employee->getName() << " retired from their job. Their regular patients will miss them.\n";
        employee->retireToCountryside();
        numEmployees--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps they were commiting tax fraud?\n";
    }
}

void Commercial::update(){
    // payTax();
}
#include "Commercial.h"

Commercial::Commercial(int cost, std::string& location, Resources& resources, int size, Citizen& owner,TaxAuthority& taxAuthority, int max, int rate) : Building(cost, location, resources, size, owner, taxAuthority) {
    this->maxEmployees = max;
    this->productionRate = rate;
    this->name = BuildingType::Shop;
}

std::string Commercial::getDetails() const {
    std::string details = "Shop: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void Commercial::produceMoney() {
    //implement
}

void Commercial::employ(Citizen& employee) {
    if (!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(&employee);
    }
}

int Commercial::pay() {
    return 3700;
}

void Commercial::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employee.fired();
        employees.erase(it);
    }
}

void Commercial::retire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}


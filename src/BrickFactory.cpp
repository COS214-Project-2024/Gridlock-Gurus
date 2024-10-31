#include "BrickFactory.h"

BrickFactory::BrickFactory(int cost, std::string& location, Resources *resources, int size, Citizen& owner, TaxAuthority& taxAuthority,BuildingType name, int productionRate, int max) : Factory(cost, location, resources, size, owner, taxAuthority,name, productionRate, max){}

std::string BrickFactory::getDetails() const {
    std::string details =  "Brick factory: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void BrickFactory::produceResource() {
    //impliment
}

void BrickFactory::employ(Citizen& employee) {
    if (!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(&employee);
    }
}

int BrickFactory::pay() {
    return 163;
}

void BrickFactory::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employee.fired();
        employees.erase(it);
    }
}


void BrickFactory::retire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), &employee);

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}

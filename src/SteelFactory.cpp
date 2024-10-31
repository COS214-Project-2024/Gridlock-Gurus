#include "SteelFactory.h"

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


int SteelFactory::pay() {
    return 163;
}


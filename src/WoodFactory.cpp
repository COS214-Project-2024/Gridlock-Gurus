#include "WoodFactory.h"

WoodFactory::WoodFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name, int productionRate, int max) : Factory(cost, location, resources, size, owner,name, productionRate, max){}


std::string WoodFactory::getDetails() const {
    std::string details =  "Wood factory: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

int WoodFactory::produceResource() {
    return 100;
}

int WoodFactory::pay() {
    return 90;
}



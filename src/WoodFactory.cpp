#include "WoodFactory.h"

WoodFactory::WoodFactory(int cost, std::string& location, Resources* resources, int size, Citizen& owner, TaxAuthority& taxAuthority, BuildingType name, int productionRate, int max) : Factory(cost, location, resources, size, owner, taxAuthority,name, productionRate, max){}


std::string WoodFactory::getDetails() const {
    std::string details =  "Wood factory: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

void WoodFactory::produceResource() {
    //impliment
}

int WoodFactory::pay() {
    return 163;
}



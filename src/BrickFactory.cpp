#include "BrickFactory.h"

BrickFactory::BrickFactory(int cost, std::string& location, Resources *resources, int size, Citizen& owner,BuildingType name, int productionRate, int max) : Factory(cost, location, resources, size, owner ,name, productionRate, max){}

/*std::string BrickFactory::getDetails() const {
    std::string details =  "Brick factory: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}*/

int BrickFactory::produceResource() {
    return 100;
}

int BrickFactory::pay() {
    return 100;
}


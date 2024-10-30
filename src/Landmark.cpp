#include "Landmark.h"
#include <iostream>


Landmark::Landmark(int cost, std::string location, Resources *resources, int size, Citizen *owner, std::weak_ptr<TaxAuthority> taxAuthority, std::string name) : Building(cost, location, resources, size, owner, taxAuthority){
    this->name = name;
}

std::string Landmark::getDetails() {
    std::string details =  "Landmark: \n";
    details += "Name: " + name + "\n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

int Landmark::pay(Citizen* citizen){
    if(citizen == owner){
        int salary = 20000;
        std::cout<< owner->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return salary;
    }
    else{
        std::cout << citizen->getName() << ", you're not the owner? Did you forge this paperwork??\n";
        return 0;
    }
}

#include "Landmark.h"

Landmark::Landmark(int cost, std::string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, string name) : Building(cost, location, resources, size, owner, taxAuthority){
    this->name = name;
}

std::string Landmark::getDetails() {
    string details =  "Residential: \n";
    details += "Name: " + name + "\n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Cost: " + to_string(cost) + "\n";
    details += "Size: " + to_string(size) + "\n";
    return details;
}

void Landmark::payTax(int amount, Citizen *owner) {
    //implement
}

#include "Landmark.h"
#include <iostream>

std::string Landmark::getDetails() const{
    std::string details =  "Landmark: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}


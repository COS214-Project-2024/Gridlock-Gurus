#include "Utilities.h"
#include <iostream>

Utilities::Utilities(std::string type, int maxProduction, int costOfRepair)
    : type(type), maxProduction(maxProduction), shedding(false), isRepair(false), costOfRepair(costOfRepair) {}

void Utilities::checkCapacity() const {
    std::cout << type << " capacity: " << maxProduction << std::endl;
}

void Utilities::shed() {
    shedding = true;
    std::cout << type << " is shedding power." << std::endl;
}

void Utilities::repair() {
    if (isRepair) {
        isRepair = false;
        std::cout << type << " repaired at a cost of " << costOfRepair << "." << std::endl;
    } else {
        std::cout << type << " is not in disrepair." << std::endl;
    }
}

void Utilities::breakUtility() {
    isRepair = true;
    std::cout << type << " is now in disrepair." << std::endl;
}

Utilities::~Utilities() {}
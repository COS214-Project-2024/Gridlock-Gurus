#include "Sanitation.h"
#include <iostream>

void Sanitation::checkCapacity() const {
    std::cout << "Sanitation system processing capacity: " << maxProduction << " liters per minute." << std::endl;
}

void Sanitation::shed() {
    if (!shedding) {
        shedding = true;
        maxProduction -= 30;
        std::cout << getTypeName() << " is now shedding." << std::endl;
    } else {
        std::cout << getTypeName() << " is already shedding." << std::endl;
    }
}

void Sanitation::repair() {
    if (isRepair) {
        isRepair = false;
        maxProduction += 300;
        std::cout << getTypeName() << " repaired and is now operational." << std::endl;
    } else {
        std::cout << getTypeName() << " does not need repairs." << std::endl;
    }
}
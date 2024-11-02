#include "Water.h"
#include <iostream>

void Water::checkCapacity() const {
    std::cout << "Water supply capacity: " << maxProduction << " liters per minute." << std::endl;
}

void Water::shed() {
    if (!shedding) {
        shedding = true;
        maxProduction -= 60;
        std::cout << getTypeName() << " is now shedding." << std::endl;
    } else {
        std::cout << getTypeName() << " is already shedding." << std::endl;
    }
}

void Water::repair() {
    if (isRepair) {
        isRepair = false;
        maxProduction += 500;
        std::cout << getTypeName() << " repaired and is now operational." << std::endl;
    } else {
        std::cout << getTypeName() << " does not need repairs." << std::endl;
    }
}
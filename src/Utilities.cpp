#include "Utilities.h"
#include <iostream>

void Utilities::checkCapacity() const {
    std::cout << " capacity: " << maxProduction << std::endl;
}

void Utilities::shed() {
    shedding = true;
    std::cout  << " is shedding power." << std::endl;
}

void Utilities::repair() {
    if (isRepair) {
        isRepair = false;
    }
}

void Utilities::breakUtility() {
    isRepair = true;
}


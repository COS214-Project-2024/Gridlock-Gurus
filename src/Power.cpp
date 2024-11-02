#include "Power.h"
#include <iostream>
#include <string>

void Power::checkCapacity() const {
    std::cout << "Power capacity is at maximum output: " << maxProduction << " MW." << std::endl;
}

void Power::shed() {
    if (!shedding) {
        shedding = true;
        maxProduction -= 200;
        std::cout << getTypeName() << " is now shedding." << std::endl;
    } else {
        std::cout << getTypeName() << " is already shedding." << std::endl;
    }
}

void Power::repair() {
    if (isRepair) {
        isRepair = false;
        maxProduction += 1000;
        std::cout << getTypeName() << " repaired and is now operational." << std::endl;
    } else {
        std::cout << getTypeName() << " does not need repairs." << std::endl;
    }
}
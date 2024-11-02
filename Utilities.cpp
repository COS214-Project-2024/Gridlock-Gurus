#include "Utilities.h"
#include <iostream>

void Utilities::checkCapacity() const {
    std::cout << "Checking capacity for utility." << std::endl;
    if (isRepair) {
        std::cout << "Utility is currently in disrepair and not operating at full capacity." << std::endl;
    } else {
        std::cout << "Utility is operating at maximum production of " << maxProduction << "." << std::endl;
    }
}

void Utilities::shed() {
    if (!shedding) {
        shedding = true;
        std::cout << "Utility is now shedding to reduce load." << std::endl;
    } else {
        std::cout << "Utility is already in load shedding mode." << std::endl;
    }
}

void Utilities::repair() {
    if (isRepair) {
        isRepair = false;
        shedding = false;
        std::cout << "Utility has been repaired. Cost: " << costOfRepair << std::endl;
    } else {
        std::cout << "Utility is not in disrepair." << std::endl;
    }
}

void Utilities::breakUtility() {
    if (!isRepair) {
        isRepair = true;
        shedding = true;
        std::cout << "Utility has broken down." << std::endl;
    } else {
        std::cout << "Utility is already broken." << std::endl;
    }
}

Utilities::~Utilities() {}
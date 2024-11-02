#include "Utilities.h"
#include <iostream>

void Utilities::checkCapacity() const {
    std::cout << "Utility type " << static_cast<int>(type) << " capacity: " << maxProduction << std::endl;
}

void Utilities::breakUtility() {
    if (!isRepair) {
        isRepair = true;
        maxProduction = 0;
        std::cout << getTypeName() << " is now broken and requires repair." << std::endl;
    } else {
        std::cout << getTypeName() << " is already broken." << std::endl;
    }
}

std::string Utilities::getTypeName() const {
    switch (type) {
        case UtilityType::Power: return "Power";
        case UtilityType::Water: return "Water";
        case UtilityType::Sanitation: return "Sanitation";
        default: return "Unknown Utility";
    }
}
#include "Sanitation.h"
#include <iostream>

void Sanitation::checkCapacity() const {
    Utilities::checkCapacity();
    std::cout << "Sanitation system processing capacity: " << maxProduction << " liters per minute." << std::endl;
}

void Sanitation::shed() {
    Utilities::shed();
    std::cout << "Sanitation utility is operating at reduced capacity." << std::endl;
}

void Sanitation::breakUtility() {
    Utilities::breakUtility();
    std::cout << "Alert: Sanitation utility failure!" << std::endl;
}

void Sanitation::repair() {
    Utilities::repair();
    std::cout << "Sanitation utility restored. Waste processing stabilized." << std::endl;
}


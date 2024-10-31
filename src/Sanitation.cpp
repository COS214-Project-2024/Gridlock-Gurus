#include "Sanitation.h"
#include <iostream>

void Sanitation::checkCapacity() const {
    std::cout << "Sanitation system processing capacity: " << maxProduction << " liters per minute." << std::endl;
}


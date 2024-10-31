#include "Sanitation.h"
#include <iostream>

Sanitation::Sanitation() : Utilities("Sanitation", 200, 200) {}

void Sanitation::checkCapacity() const {
    std::cout << "Sanitation system processing capacity: " << maxProduction << " liters per minute." << std::endl;
}

Sanitation::~Sanitation() {}
#include "Water.h"
#include <iostream>

Water::Water() : Utilities("Water", 500, 300) {}

void Water::checkCapacity() const {
    std::cout << "Water supply capacity: " << maxProduction << " liters per minute." << std::endl;
}

Water::~Water() {}
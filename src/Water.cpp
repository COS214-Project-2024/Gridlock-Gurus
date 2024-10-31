#include "Water.h"
#include <iostream>

void Water::checkCapacity() const {
    std::cout << "Water supply capacity: " << maxProduction << " liters per minute." << std::endl;
}


#include "Power.h"
#include <iostream>

Power::Power() : Utilities("Power", 1000, 500) {}

void Power::checkCapacity() const {
    std::cout << "Power capacity is at maximum output: " << maxProduction << " MW." << std::endl;
}

Power::~Power() {}
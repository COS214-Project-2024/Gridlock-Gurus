#include "Power.h"
#include <iostream>
#include <string>


void Power::checkCapacity() const {
    std::cout << "Power capacity is at maximum output: " << maxProduction << " MW." << std::endl;
}


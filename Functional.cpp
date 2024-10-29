#include "Functional.h"
#include <iostream>

void Functional::checkCapacity(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " is fully functional." << std::endl;
}

void Functional::breakTransport(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " has broken down." << std::endl;
}

void Functional::repair(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " is already functional and does not need anymore repairs." << std::endl;
}

TransportState* Functional::returnState() {
    return this;
}

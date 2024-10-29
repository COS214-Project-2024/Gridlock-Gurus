#include "Broken.h"
#include <iostream>

void Broken::checkCapacity(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " has broken down and requires repair." << std::endl;
}

void Broken::breakTransport(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " is out of commission for the time being." << std::endl;
}

void Broken::repair(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " has been repaired." << std::endl;
}

TransportState* Broken::returnState() {
    return this;
}

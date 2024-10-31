#include "Damaged.h"
#include <iostream>

void Damaged::checkCapacity(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " is damaged and cannot operate properly." << std::endl;
}

void Damaged::breakTransport(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " is now completely broken and is out of commission for the time being." << std::endl;
}

void Damaged::repair(Vehicle* vehicle) {
    std::cout << vehicle->getType() << " has been repaired." << std::endl;
}

TransportState* Damaged::returnState() {
    return this;
}

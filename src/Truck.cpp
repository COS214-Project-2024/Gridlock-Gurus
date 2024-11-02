#include "Truck.h"
#include <iostream>

#include "Broken.h"

Truck::Truck(int capacity, TransportDepartment* department) : Vehicle("Truck", capacity, department) {}

void Truck::checkState() {
    if (getState()) {
        getState()->checkCapacity(this);
    }
    else {
        std::cout << "Truck has no assigned state!" << std::endl;
    }
}

void Truck::collect(int amount) {
    std::cout << "Truck collected " << amount << " units of cargo." << std::endl;
}

void Truck::run() {
    std::cout << "Truck is running." << std::endl;
}

void Truck::breakDown() {
    std::cout << "Truck has broken down!" << std::endl;
    setState(new Broken());
}

void Truck::delay() {
    std::cout << "Truck is delayed." << std::endl;
}

Vehicle* Truck::clone() {
    return new Truck(capacity, department);
}

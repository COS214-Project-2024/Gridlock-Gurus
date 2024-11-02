#include "Taxi.h"
#include <iostream>

#include "Broken.h"
#include "Damaged.h"

Taxi::Taxi(int capacity, TransportDepartment& department) : Vehicle("Taxi", capacity, department) {}

void Taxi::checkState() {
    if (getState()) {
        getState()->checkCapacity(this);
    }
    else {
        std::cout << "Taxi has no assigned state!" << std::endl;
    }
}

void Taxi::collect(int amount) {
    std::cout << "Taxi collected " << amount << " units of fare." << std::endl;
}

void Taxi::run() {
    std::cout << "Taxi is running." << std::endl;
}

void Taxi::breakDown() {
    std::cout << "Taxi has broken down!" << std::endl;
    setState(new Broken());
}

void Taxi::delay() {
    std::cout << "Taxi is delayed." << std::endl;
    setState(new Damaged());
}

Vehicle* Taxi::clone() {
    return new Taxi(capacity, department);
}

void Taxi::repair() {
    if (getState()) {
        getState()->repair(this);
    }
}

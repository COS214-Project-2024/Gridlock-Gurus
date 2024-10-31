#include "Taxi.h"
#include <iostream>

Taxi::Taxi(int capacity) : Vehicle("Taxi", capacity) {}

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
    if (getState()) {
        getState()->breakTransport(this);
    }
}

void Taxi::delay() {
    std::cout << "Taxi is delayed." << std::endl;
}

Vehicle* Taxi::clone() {
    return new Taxi(capacity);
}

void Taxi::repair() {
    if (getState()) {
        getState()->repair(this);
    }
}

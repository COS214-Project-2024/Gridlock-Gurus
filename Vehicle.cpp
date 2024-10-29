#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string& type, int capacity)
    : type(type), capacity(capacity), currentPassengers(0), state(nullptr) {}

void Vehicle::setState(TransportState* newState) {
    state = newState;
}

TransportState* Vehicle::getState() const {
    return state;
}

std::string Vehicle::getType() const {
    return type;
}

void Vehicle::load(int passengers) {
    if (currentPassengers + passengers <= capacity) {
        currentPassengers += passengers;
        std::cout << passengers << " passengers loaded into "
            << type << ". Current: " << currentPassengers
            << "/" << capacity << std::endl;
    }
    else {
        std::cout << "Cannot load passengers: Over capacity!" << std::endl;
    }
}

void Vehicle::offload() {
    std::cout << "Offloading all passengers from " << type
        << ". Previous: " << currentPassengers << "/" << capacity << std::endl;
    currentPassengers = 0;
}

void Vehicle::collect(int amount) {
    std::cout << "Collected " << amount << " units of cargo in " << type << "." << std::endl;
}

void Vehicle::run() {
    std::cout << type << " is running." << std::endl;
}

void Vehicle::breakDown() {
    std::cout << type << " has broken down!" << std::endl;
    if (state) {
        state->breakTransport(this);
    }
}

void Vehicle::delay() {
    std::cout << type << " is delayed." << std::endl;
}

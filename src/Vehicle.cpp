#include "Vehicle.h"
#include <iostream>
#include "Damaged.h"
#include "Functional.h"
#include "Broken.h"

Vehicle::Vehicle(const std::string& type, int capacity, TransportDepartment& transportDept)
    : type(type), capacity(capacity), currentPassengers(0), state(new Functional()),
      department(transportDept), usageCount(0) {}

void Vehicle::setState(TransportState* newState) {
    state = newState;
}

TransportState* Vehicle::getState() const {
    return state;
}

std::string Vehicle::getType() const {
    return type;
}

void Vehicle::updateState() {
    if(usageCount > 10) {
        if(dynamic_cast<Functional*>(state)) {
            delay();
        } else if(dynamic_cast<Damaged*>(state)){
            breakDown();
        }
    }
    if(dynamic_cast<Damaged*>(state)){
        requestRepair();
    }
}

void Vehicle::requestRepair() {
    
        std::cout << "Requesting repair for " << type << "." << std::endl;
        department->manage();
    
}

void Vehicle::incrementUsage() {
    currentPassengers++;
    updateState();
}

void Vehicle::load(int passengers) {
    if (currentPassengers + passengers <= capacity) {
        currentPassengers += passengers;
        incrementUsage();
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

void Vehicle::repair() {
    usageCount = 0;
}

void Vehicle::delay() {
    std::cout << type << " is delayed." << std::endl;
}

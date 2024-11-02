#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(VehicleType type, int capacity, TransportDepartment& transportDep): department(transportDep) {
    type = type;
    capacity = capacity;
    currentPassengers = 0;
    state = std::make_unique<Functional>();
    vehicle_state = VehicleState::Functional;
    int usageCount = 0;
}

Vehicle* Vehicle::clone() {
    return new Vehicle(type,capacity,department);
}

bool Vehicle::run() {
    state->run();
}

void Vehicle::setState() {
    if(vehicle_state == VehicleState::Functional) {
        state = std::make_unique<BrokenState>();
        vehicle_state = VehicleState::Broken;
        requestRepair();
    } else {
        state = std::make_unique<FunctionalState>();
        vehicle_state = VehicleState::Functional;
    }
}

void Vehicle::offload() {
    currentPassengers = 0;
}

void Vehicle::collect(int passengers) {
    if (currentPassengers + passengers <= capacity) {
        currentPassengers += passengers;
        usageCount++;
        run();
    } else {
        // else just break
        setState();
    }
}

void Vehicle::requestRepair() {
    department.manage();
}

void Vehicle::repair() {
    usageCount = 0;
    state = std::make_unique<FunctionalState>();
    vehicle_state = VehicleState::Functional;
}



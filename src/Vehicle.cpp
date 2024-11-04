#include "Vehicle.h"
#include <iostream>

/**
 * @brief Constructs a new Vehicle object with the specified type and capacity.
 * @param type Type of vehicle (e.g., taxi, bus).
 * @param capacity Maximum passenger capacity of the vehicle.
 * @param transportDep Reference to the TransportDepartment managing this vehicle.
 */
Vehicle::Vehicle(VehicleType type, int capacity, TransportDepartment& transportDep): department(transportDep) {
    this->type = type;
    this->capacity = capacity;
    this->usageCount = 0;
    currentPassengers = 0;
    state = std::make_unique<FunctionalState>();
    vehicle_state = VehicleState::Functional;
}

/**
 * @brief Creates a copy of this vehicle.
 * @return A pointer to a new Vehicle object that is a clone of this vehicle.
 */
Vehicle* Vehicle::clone() {
    return new Vehicle(type,capacity,department);
}

/**
 * @brief Runs the vehicle, resetting the passenger count to zero.
 * @return A boolean indicating the success of the vehicle operation.
 */
bool Vehicle::run() {
    offload();
    return state->run();
}

/**
 * @brief Sets the vehicle's state between functional and broken.
 *
 * If the vehicle is functional, it will be set to broken and a repair request will be issued.
 */
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

/**
 * @brief Offloads all passengers from the vehicle.
 */
void Vehicle::offload() {
    currentPassengers = 0;
}

/**
 * @brief Collects a specified number of passengers.
 *
 * If the new total exceeds capacity, the vehicle is marked as broken.
 *
 * @param passengers Number of passengers to add.
 */
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

/**
 * @brief Sends a request to the transport department to manage vehicle repairs.
 */
void Vehicle::requestRepair() {
    department.manage();
}

/**
 * @brief Repairs the vehicle, resetting its usage count and marking it as functional.
 */
void Vehicle::repair() {
    usageCount = 0;
    state = std::make_unique<FunctionalState>();
    vehicle_state = VehicleState::Functional;
}



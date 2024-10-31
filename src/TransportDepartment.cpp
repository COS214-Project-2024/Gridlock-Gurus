#include "TransportDepartment.h"
#include <iostream>
#include <stdexcept>

void TransportDepartment::addVehicle(Vehicle* vehicle) {
    vehicles.push_back(vehicle);
}

void TransportDepartment::manage() {
    for (auto& vehicle : vehicles) {
        vehicle->checkState();
    }
}

Vehicle* TransportDepartment::getAvailableVehicle(const std::string& type) {
    for (auto& vehicle : vehicles) {
        if (vehicle->getType() == type && vehicle->getState()) {
            return vehicle;
        }
    }
    throw std::runtime_error("No available vehicle of type: " + type);
}

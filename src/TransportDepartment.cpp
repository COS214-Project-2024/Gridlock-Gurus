#include "TransportDepartment.h"
#include <iostream>
#include <stdexcept>

void TransportDepartment::addVehicle(Vehicle& vehicle) {
    vehicles.push_back(vehicle);
}

void TransportDepartment::manage() {
     std::map<VehicleType, int> functionalCounts;

    for (auto& vehicle : vehicles) {
        if (vehicle->getState() == VehicleState::Functional) {
            functionalCounts[vehicle->getType()]++;
        }
    }

    for (auto& vehicle : vehicles) {
        if (vehicle->getState() == VehicleState::Broken) {
            if (functionalCounts[vehicle->getType()] < (vehicles.size() / 2)) {
                repairVehicles(vehicle);
            }
        }
    }
}

TransportDepartment::~TransportDepartment() {
    for (Vehicle* v : vehicles) {
            delete v;
    }
}

Vehicle& TransportDepartment::getAvailableVehicle(VehicleType type) {
    for (Vehicle* vehicle : vehicles) {
        if (vehicle->getType() == type) {
            if (vehicle->getState() && VehicleState::Functional) {
                return *vehicle;
            }
        }
    }
}

void TransportDepartment::repairVehicles(Vehicle* vehicle) {
    std::cout << "Repairing Vehicle Fleet." << std::endl;
    if (vehicle->getState() == VehicleState::Broken) {
        vehicle->repair();
    }
}


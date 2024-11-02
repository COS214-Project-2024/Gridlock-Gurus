#include "TransportDepartment.h"
#include <iostream>
#include <stdexcept>
#include "TransportState.h"
#include "Broken.h"
#include "Functional.h"

void TransportDepartment::addVehicle(Vehicle* vehicle) {
    vehicles.push_back(vehicle);
}

void TransportDepartment::manage() {
    int functionalCount = 0;
    for (auto& vehicle : vehicles) {
        vehicle->checkState();
        if (vehicle->getState() && dynamic_cast<Functional*>(vehicle->getState())) {
            functionalCount++;
        }
    }

    if (functionalCount < vehicles.size() / 2) {
        for (auto& vehicle : vehicles) {
            if (vehicle->getState() && dynamic_cast<Broken*>(vehicle->getState())) {
                repairVehicles(vehicle);
            }
        }
    }
}

Vehicle* TransportDepartment::getAvailableVehicle(const std::string& type) {
    for (auto& vehicle : vehicles) {
        if (vehicle->getType() == type && vehicle->getState() &&
            !dynamic_cast<Broken*>(vehicle->getState())) {
            return vehicle;
            }
    }
    throw std::runtime_error("No available vehicle of type: " + type);
}


void TransportDepartment::repairVehicles(Vehicle* vehicle) {
    std::cout << "Repairing " << vehicle->getType() << "." << std::endl;
    vehicle->setState(new Functional());
    vehicle->repair();
}

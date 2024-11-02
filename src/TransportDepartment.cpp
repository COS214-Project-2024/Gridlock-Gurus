#include "TransportDepartment.h"
#include <iostream>
#include <map>
#include <stdexcept>
#include "TransportState.h"
#include "Broken.h"
#include "Damaged.h"
#include "Functional.h"

void TransportDepartment::addVehicle(Vehicle* vehicle) {
    vehicles.push_back(vehicle);
}

TransportDepartment::~TransportDepartment() {
    for (Vehicle* v : vehicles) {
            delete v;
    }

    //buildings.clear();
}

void TransportDepartment::manage() {
    std::map<std::string, int> functionalCounts;

    for (auto& vehicle : vehicles) {
        vehicle->checkState();
        if (vehicle->getState() && dynamic_cast<Functional*>(vehicle->getState())) {
            functionalCounts[vehicle->getType()]++;
        }
    }

    for (auto& vehicle : vehicles) {
        if (vehicle->getState() && dynamic_cast<Broken*>(vehicle->getState())) {
            if (functionalCounts[vehicle->getType()] < (vehicles.size() / 2)) {
                repairVehicles(vehicle);
            }
        }
    }
}


Vehicle* TransportDepartment::getAvailableVehicle(const std::string& type) {
    for (auto& vehicle : vehicles) {
        if (vehicle->getType() == type) {
            if (vehicle->getState() && dynamic_cast<Functional*>(vehicle->getState())) {
                return vehicle;
            }
            if(vehicle->getState() && dynamic_cast<Damaged*>(vehicle->getState())) {
                return vehicle;
            }
        }
    }
    std::cout<<"No drivers were found."<<std::endl;
    throw std::runtime_error("No available vehicle of type: " + type);
}


void TransportDepartment::repairVehicles(Vehicle* vehicle) {
    std::cout << "Repairing " << vehicle->getType() << "." << std::endl;
    if (dynamic_cast<Broken*>(vehicle->getState())) {
        delete vehicle->getState();
        vehicle->setState(new Functional());
        vehicle->repair();
    }
}


#include "TransportDepartment.h"
#include <iostream>
#include <stdexcept>

#include <map>

void TransportDepartment::addVehicle(Vehicle& vehicle) {
    vehicles.push_back(&vehicle);
}

void TransportDepartment::manage() {
    int count = 0;
    for(Vehicle* v : vehicles) {
        if(v->getState() == VehicleState::Broken) {
            count++;
        }
    }

    if(count == vehicles.size()/2){
        for(Vehicle* v : vehicles) {
            if(v->getState() == VehicleState::Broken) {
                repairVehicle(*v);
            }
        }
    }

}

int TransportDepartment::getBroken() {
    int count = 0;
    for(Vehicle* v : vehicles) {
        if(v->getState() == VehicleState::Broken) {
            count++;
        }
    }
    return count;
}

TransportDepartment::~TransportDepartment() {
    for (Vehicle* v : vehicles) {
            delete v;
    }
}

Vehicle& TransportDepartment::getAvailableVehicle(VehicleType type) {
    for (Vehicle* vehicle : vehicles) {
        if (vehicle->getType() == type) {
            if (vehicle->getState() == VehicleState::Functional) {
                return *vehicle;
            }
        }
    }

    Vehicle* v = new Vehicle(VehicleType::Taxi,4,*this);
    addVehicle(*v);

    return *v;
}

void TransportDepartment::repairVehicle(Vehicle& vehicle) {
    std::cout << "Repairing Vehicle Fleet." << std::endl;
    if (vehicle.getState() == VehicleState::Broken) {
        vehicle.repair();
    }
}

void TransportDepartment::addTransport(VehicleType type) {
    Vehicle* v = new Vehicle(type,4,*this);
    vehicles.push_back(v);
}

int TransportDepartment::getFleetSize() {
    return vehicles.size();
}

void TransportDepartment::getReport(std::string& temp) {
    temp+= "Working Vehicles: ";
    temp += std::to_string(getFleetSize()-getBroken());
    temp += "\nBroken Vehicles: ";
    temp += std::to_string(getBroken());
    temp += "\nTotal Vehicles: ";
    temp += std::to_string(getFleetSize());
    temp += "\n";
}

std::vector<Vehicle*>& TransportDepartment::getFleet() {
 return vehicles;
}


#include "TransportDepartment.h"
#include <iostream>
#include <stdexcept>

#include <map>

/**
 * @brief Adds a vehicle to the transport department.
 * @param vehicle The vehicle to add.
 */
void TransportDepartment::addVehicle(Vehicle& vehicle) {
    vehicles.push_back(&vehicle);
}

/**
 * @brief Manages the fleet by repairing vehicles if half or more are broken.
 */
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

/**
 * @brief Counts and returns the number of broken vehicles in the fleet.
 * @return The number of broken vehicles.
 */
int TransportDepartment::getBroken() {
    int count = 0;
    for(Vehicle* v : vehicles) {
        if(v->getState() == VehicleState::Broken) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Destructor that deletes all vehicles in the fleet.
 */
TransportDepartment::~TransportDepartment() {
    for (Vehicle* v : vehicles) {
            delete v;
    }
}

/**
 * @brief Retrieves an available vehicle of a specified type. If none are available, a new vehicle of that type is added.
 * @param type The type of vehicle to retrieve.
 * @return A reference to the available or newly created vehicle.
 */
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

/**
 * @brief Repairs a specified broken vehicle.
 * @param vehicle The vehicle to repair.
 */
void TransportDepartment::repairVehicle(Vehicle& vehicle) {
    std::cout << "Repairing Vehicle Fleet." << std::endl;
    if (vehicle.getState() == VehicleState::Broken) {
        vehicle.repair();
    }
}

/**
 * @brief Adds a new transport vehicle of a specified type to the fleet.
 * @param type The type of vehicle to add.
 */
void TransportDepartment::addTransport(VehicleType type) {
    Vehicle* v = new Vehicle(type,4,*this);
    vehicles.push_back(v);
}

/**
 * @brief Retrieves the total size of the fleet.
 * @return The fleet size.
 */
int TransportDepartment::getFleetSize() {
    return vehicles.size();
}

/**
 * @brief Generates a report of the fleet's operational status and broken vehicle count.
 * @param temp A string reference to store the fleet report.
 */
void TransportDepartment::getReport(std::string& temp) {
    temp+= "Working Vehicles: ";
    temp += std::to_string(getFleetSize()-getBroken());
    temp += "\nBroken Vehicles: ";
    temp += std::to_string(getBroken());
    temp += "\nTotal Vehicles: ";
    temp += std::to_string(getFleetSize());
    temp += "\n";
}

/**
 * @brief Retrieves the list of all vehicles in the fleet.
 * @return A reference to the vector of vehicles.
 */
std::vector<Vehicle*>& TransportDepartment::getFleet() {
 return vehicles;
}


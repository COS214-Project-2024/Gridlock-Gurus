#include "Citizen.h"
#include <iostream>

Citizen::Citizen(const std::string& name, int id)
    : name(name), id(id), currentVehicle(nullptr) {}

std::string Citizen::getName() const {
    return name;
}

int Citizen::getId() const {
    return id;
}

void Citizen::callTransport(TransportDepartment& department, const std::string& type) {
    try {
        Vehicle* vehicle = department.getAvailableVehicle(type);
        std::cout << name << " called a " << type << "." << std::endl;
        boardVehicle(vehicle);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Citizen::boardVehicle(Vehicle* vehicle) {
    if (currentVehicle != nullptr) {
        std::cout << name << " is already in a vehicle." << std::endl;
        return;
    }
    currentVehicle = vehicle;
    std::cout << name << " boarded " << vehicle->getType() << "." << std::endl;
}

void Citizen::offloadVehicle() {
    if (currentVehicle == nullptr) {
        std::cout << name << " is not on a vehicle." << std::endl;
        return;
    }
    std::cout << name << " offloaded from " << currentVehicle->getType() << "." << std::endl;
    currentVehicle = nullptr;
}

bool Citizen::isInVehicle() const {
    return currentVehicle != nullptr;
}

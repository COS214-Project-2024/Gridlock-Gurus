#include "Citizen.h"
#include "NameGenerator.h"
#include <iostream>

Citizen::Citizen(int id,CitizenType type, int satisfactionLevel, int funds,std::weak_ptr<TaxAuthority> taxAuthority)
: taxAuthority(taxAuthority),id(id),type(type), satisfactionLevel(satisfactionLevel), funds(funds),employmentStatus(false),retired(false){

    this->home = nullptr;
    this->placeOfWork = nullptr;
    this->currentVehicle = nullptr;
    this->name = NameGenerator::getInstance().getRandomName();
}

void Citizen::setWork(Building& work){
    placeOfWork = &work;
    employmentStatus = true;
    type = CitizenType::Worker;
    if(satisfactionLevel < 100) {
        satisfactionLevel += 10;
    }
}

void Citizen::setHome(Building& home){
    this->home = &home;
    if(satisfactionLevel < 100) {
        satisfactionLevel += 10;
    }
}

void Citizen::workDay(){
    if (employmentStatus && placeOfWork) {
        collectSalary();
    }
}

void Citizen::collectSalary(){
    if (placeOfWork) {
        this->funds += placeOfWork->pay();
    }
}

void Citizen::payTaxes(int amount){
    if (employmentStatus) {
        if (funds >= amount) {
            funds -= amount;
            if(auto taxAuth = taxAuthority.lock()) {
                taxAuth->sendTax(amount);
            }
        } 
    }
}

void Citizen::retire(){
    type = CitizenType::Retired;
    employmentStatus = false;
    retired = true;
    placeOfWork = nullptr;
    if(satisfactionLevel < 100)
            satisfactionLevel += 5;
}

void Citizen::retireToCountryside(){
    retire();
    home = nullptr;
    if(satisfactionLevel < 100)
            satisfactionLevel += 5;
}

void Citizen::fired(){
    type = CitizenType::Citizen;
    employmentStatus = false;
    placeOfWork = nullptr;
    satisfactionLevel -= 5;
}

void Citizen::callTransport(TransportDepartment& department, const std::string& type) {
    try {
        Vehicle* vehicle = department.getAvailableVehicle(type);
        std::cout << name << " called a " << type << "." << std::endl;
        boardVehicle(vehicle);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        throw;
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



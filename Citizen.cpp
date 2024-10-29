#include "Citizen.h"
#include "NameGenerator.h"
#include <iostream>

Citizen::Citizen(std::string type, int satisfactionLevel, int funds,std::weak_ptr<TaxAuthority> taxAuthority){
    this->type = type;
    this->satisfactionLevel = satisfactionLevel;
    this->funds = funds;
    this->employmentStatus = false;
    this->retired = false;
    this->home = nullptr;
    this->placeOfWork = nullptr;
    this->taxAuthroity = taxAuthority;
    this->currentVehicle = nullptr;
    this->name = NameGenerator::getInstance().getRandomName();
    this->id = NameGenerator::getInstance().getRandomID();
}

void Citizen::findWork(Building* placeOfEmployment){
    if (placeOfEmployment) {
        placeOfWork = placeOfEmployment;
        employmentStatus = true;
        if(satisfactionLevel < 100)
            satisfactionLevel += 10;
    }
}

void Citizen::findHome(Building* home){
    if (home) {
        this->home = home;
        if(satisfactionLevel < 100)
            satisfactionLevel += 10;
    }
}

void Citizen::workDay(){
    if (employmentStatus && placeOfWork) {
        collectSalary(placeOfWork);
    }
}

void Citizen::collectSalary(Building* placeOfWork){
    if (placeOfWork) {
        int salary = placeOfWork->pay(this);
        funds += salary;
        // satisfactionLevel += 1;
    }
}

void Citizen::payTaxes(int amount){
    if (employmentStatus) {
        if (funds >= amount) {
            funds -= amount;
            taxAuthority->sendTax(amount);
        } // calculateCitizenTax(getFunds())
    }
}

// void Citizen::update(){
//     // if (taxAuthority) {
//     //     payTaxes();
//     //     satisfactionLevel -= 5;
//     // }
// }

void Citizen::retire(){
    type = "retiree";
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

void Citizen::quitJob(){
    type = "citizen";
    employmentStatus = false;
    placeOfWork = nullptr;
    satisfactionLevel -= 5;
}

void Citizen::fired(){
    type = "citizen";
    employmentStatus = false;
    placeOfWork = nullptr;
    satisfactionLevel -= 5;
}

std::string Citizen::getName() {
    return name;
}

bool Citizen::getEmploymentStatus() {
    if(employmentStatus == true || retired == true) {
        return true;
    } else {
        return false;
    }
}

int Citizen::getFunds() {
    return funds;
}

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


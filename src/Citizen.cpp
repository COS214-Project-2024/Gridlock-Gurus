#include "Citizen.h"
#include "NameGenerator.h"
#include "VehicleType.h"
#include <iostream>

Citizen::Citizen(int id,CitizenType type, int satisfactionLevel, int funds,std::weak_ptr<TaxAuthority> taxAuthority)
: taxAuthority(taxAuthority),id(id),type(type), satisfactionLevel(satisfactionLevel), funds(funds),employmentStatus(false),retired(false){

    this->home = nullptr;
    this->placeOfWork = nullptr;
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

void Citizen::quitJob() {
    if (employmentStatus && placeOfWork) {
        //placeOfWork->retire(*this);
    }
}

void Citizen::retire(){
    type = CitizenType::Retired;
    employmentStatus = false;
    retired = true;
    //home->removeTenant(*this);
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

void Citizen::callTransport(TransportDepartment& department, VehicleType type) {
    Vehicle& vehicle = department.getAvailableVehicle(type);
}



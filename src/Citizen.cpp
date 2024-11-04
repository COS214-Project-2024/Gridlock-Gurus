#include "Citizen.h"
#include "NameGenerator.h"
#include "VehicleType.h"
#include <iostream>

/**
 * @brief Constructs a Citizen with the specified attributes.
 * @param id Unique identifier for the citizen.
 * @param type Type of citizen (e.g., Worker, Retired).
 * @param satisfactionLevel Initial satisfaction level of the citizen.
 * @param funds Initial funds available to the citizen.
 * @param taxAuthority Weak pointer to the TaxAuthority managing taxes for the citizen.
 */
Citizen::Citizen(int id,CitizenType type, int satisfactionLevel, int funds,std::weak_ptr<TaxAuthority> taxAuthority)
: taxAuthority(taxAuthority),id(id),type(type), satisfactionLevel(satisfactionLevel), funds(funds),employmentStatus(false),retired(false){

    this->home = nullptr;
    this->placeOfWork = nullptr;
    this->name = NameGenerator::getInstance().getRandomName();
}

/**
 * @brief Sets the workplace for the citizen.
 * @param work Reference to the building where the citizen works.
 */
void Citizen::setWork(Building& work){
    placeOfWork = &work;
    employmentStatus = true;
    type = CitizenType::Worker;
    if(satisfactionLevel < 100) {
        satisfactionLevel += 10;
    }
}

/**
 * @brief Sets the home for the citizen.
 * @param home Reference to the building where the citizen resides.
 */
void Citizen::setHome(Building& home){
    this->home = &home;
    if(satisfactionLevel < 100) {
        satisfactionLevel += 10;
    }
}


/**
 * @brief Simulates a workday for the citizen, allowing salary collection.
 */
void Citizen::workDay(){
    if (employmentStatus && placeOfWork) {
        collectSalary();
    }
}

/**
 * @brief Collects salary from the workplace.
 */
void Citizen::collectSalary(){
    if (placeOfWork) {
        this->funds += placeOfWork->pay();
    }
}

/**
 * @brief Pays taxes, reducing the citizen's funds accordingly.
 * @param amount Amount of taxes to be paid.
 */
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

/**
 * @brief Quits the citizen's job, removing them from the workplace.
 */
void Citizen::quitJob() {
    if (employmentStatus && placeOfWork) {
        //placeOfWork->retire(*this);
    }
}

/**
 * @brief Retires the citizen, updating their status and satisfaction level.
 */
void Citizen::retire(){
    type = CitizenType::Retired;
    employmentStatus = false;
    retired = true;
    //home->removeTenant(*this);
    placeOfWork = nullptr;
    if(satisfactionLevel < 100)
            satisfactionLevel += 5;
}

/**
 * @brief Retires the citizen to the countryside, removing their home.
 */
void Citizen::retireToCountryside(){
    retire();
    home = nullptr;
    if(satisfactionLevel < 100)
            satisfactionLevel += 5;
}

/**
 * @brief Marks the citizen as fired, updating their status and satisfaction level.
 */
void Citizen::fired(){
    type = CitizenType::Citizen;
    employmentStatus = false;
    placeOfWork = nullptr;
    satisfactionLevel -= 5;
}

/**
 * @brief Calls for transportation from the transport department.
 * @param department Reference to the transport department.
 * @param type Type of vehicle requested.
 */
void Citizen::callTransport(TransportDepartment& department, VehicleType type) {
    Vehicle& vehicle = department.getAvailableVehicle(type);
}



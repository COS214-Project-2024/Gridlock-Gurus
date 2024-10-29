#include "Citizen.h"
#include "NameGenerator.h"

Citizen::Citizen(std::string type, int satisfactionLevel, int funds,std::weak_ptr<TaxAuthority> taxAuthority){
    this->type = type;
    this->satisfactionLevel = satisfactionLevel;
    this->funds = funds;
    this->employmentStatus = false;
    this->retired = false;
    this->home = nullptr;
    this->placeOfWork = nullptr;
    this->taxAuthroity = taxAuthority;
    name = NameGenerator::getInstance().getRandomName();
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

void Citizen::update(){
    // if (taxAuthority) {
    //     payTaxes();
    //     satisfactionLevel -= 5;
    // }
}

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
    type = "unemployed";
    employmentStatus = false;
    placeOfWork = nullptr;
    satisfactionLevel -= 5;
}

void Citizen::fired(){
    type = "unemployed";
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

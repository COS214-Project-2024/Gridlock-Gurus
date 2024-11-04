#include "DepartmentOfHomeAffairs.h"
#include "CitizenType.h"
#include <random>

DepartmentOfHomeAffairs::DepartmentOfHomeAffairs(std::shared_ptr<TaxAuthority> taxAuth) : taxAuthority(taxAuth){
    this->population = 0;
    this->factory = std::make_unique<CitizenFactory>(taxAuth);
}

DepartmentOfHomeAffairs::~DepartmentOfHomeAffairs() {
    taxAuthority->deregisterAllCitizens();

    for (Citizen* citizen : citizens) {
        if(citizen) {
            citizen->quitJob();
            delete citizen;
        }
    }
     citizens.clear();
}

void DepartmentOfHomeAffairs::registerBirth() {
    citizens.push_back(factory->createCitizen(CitizenType::Worker, 100, 1000));
    ++population;
}

void DepartmentOfHomeAffairs::registerDeath(Citizen& citizen) {
     auto it = std::find(citizens.begin(), citizens.end(), &citizen);
    
    if (it != citizens.end()) {
        delete *it;
        citizens.erase(it);  
        --population;
    }
}

int DepartmentOfHomeAffairs::calculateAvgHappiness() {
    if(citizens.size() == 0) return 0;

    int average = 0;
    for(Citizen* c: citizens){
        average += c->getSatisfactionLevel();
    }

    average /= citizens.size();

    return average;
}

void DepartmentOfHomeAffairs::fillHomeWithTenants(Residential& home) {
    while(!home.isFull()) {
        Citizen* c = factory->createCitizen(CitizenType::Citizen, 100, 1000);
        citizens.push_back(c);
        home.addTenant(*c);
        ++population;
    }
}

void DepartmentOfHomeAffairs::fillWorkWithEmployees(Factory& work) {
    while(!work.isFull()) {
        Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
        citizens.push_back(c);
        work.employ(*c);
        ++population;
    }
}

void DepartmentOfHomeAffairs::fillWorkWithEmployees(Service& work) {
    while(!work.isFull()) {
            Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
            citizens.push_back(c);
            work.employ(*c);
            ++population;
        }
}

void DepartmentOfHomeAffairs::fillWorkWithEmployees(Commercial& work){
    while(!work.isFull()) {
            Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
            citizens.push_back(c);
            work.employ(*c);
            ++population;
        }
}

Citizen& DepartmentOfHomeAffairs::getRandomCitizen(){
    // Ensure the vector is not empty
    if (citizens.empty()) {
        Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
        citizens.push_back(c);
        ++population;
        return *c;
    }

    std::random_device rd;                         
    std::mt19937 gen(rd());                           
    std::uniform_int_distribution<> dist(0, citizens.size() - 1);  
    int randomIndex = dist(gen);             
    return *citizens[randomIndex];  
}

std::string DepartmentOfHomeAffairs::createCitizen(CitizenType type, int satisfaction, int funds){
    Citizen* c = factory->createCitizen(type, satisfaction, funds);
    std::string name = c->getName();
    citizens.push_back(c);
    ++population;
    return name + " was created with $" + std::to_string(funds) + " in their account.";
}

std::string DepartmentOfHomeAffairs::getCitizenDetails(int id) {
    std::string details = "";
    for(Citizen* c : citizens) {
        if(c->getId() == id) {
            details += "#";
            details += std::to_string(c->getId());
            details += "\nName:\t";
            details += c->getName();
            details += "\nFunds:\t";
            details += std::to_string(c->getFunds());
            details += "\nSatisfaction Level:\t";
            details += std::to_string(c->getSatisfactionLevel());
        }
    }
    return details;
}

Citizen& DepartmentOfHomeAffairs::getCitizen(int id) {
    for (Citizen* c : citizens) {
        if(c->getId() == id) {
            return *c;
        }
    }
    return getRandomCitizen();
}

std::vector<Citizen*>& DepartmentOfHomeAffairs::getCitizens() {
    return citizens;
}

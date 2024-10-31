#include "DepartmentOfHomeAffairs.h"

DepartmentOfHomeAffairs::DepartmentOfHomeAffairs(TaxAuthority* taxAuth) {
    this->population = 0;
    this->taxAuthority = taxAuth;
    this->faxtory = new CitizenFactory(taxAuth);
    //this->iterator = nullptr;
}

DepartmentOfHomeAffairs::~DepartmentOfHomeAffairs() {
    if(factory) {
        delete factory;
    }

    if(iterator) {
        delete iterator;
    }

    for (Citizen* citizen : citizens) {
        if(citizen) {
            delete citizen;
        }
    }

    citizens.clear();
}

void DepartmentOfHomeAffairs::registerBirth() {
    std::string type = "worker";
    int startingSatisfaction = 100;
    int startingFunds = 1000;

    Citizen* newCitizen = factory->createCitizen(type, startingSatisfaction, startingFund);

    citizens.push_back(newCitizen);
    ++population;
}

void DepartmentOfHomeAffairs::registerDeath(Citizen* citizen) {
    auto it = std::find(citizens.begin(), citizens.end(), citizen);
    if (it != citizens.end()) {
        delete *it;
        citizens.erase(it);
        --population;
    }
}

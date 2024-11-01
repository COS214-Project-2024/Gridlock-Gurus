#include "DepartmentOfHomeAffairs.h"
#include "CitizenType.h"

DepartmentOfHomeAffairs::DepartmentOfHomeAffairs(std::shared_ptr<TaxAuthority> taxAuth) : taxAuthority(taxAuth){
    this->population = 0;
    this->factory = std::make_unique<CitizenFactory>(taxAuth);
}

DepartmentOfHomeAffairs::~DepartmentOfHomeAffairs() {
    for (Citizen* citizen : citizens) {
        if(citizen) {
            delete citizen;
        }
    }

    citizens.clear();
}

void DepartmentOfHomeAffairs::registerBirth() {
    CitizenType type = CitizenType::Worker;
    int startingSatisfaction = 100;
    int startingFunds = 1000;

    citizens.push_back(factory->createCitizen(type, startingSatisfaction, startingFunds));

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

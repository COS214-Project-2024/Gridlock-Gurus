#include "DepartmentOfHomeAffairs.h"

DepartmentOfHomeAffairs::DepartmentOfHomeAffairs(std::shared_ptr<TaxAuthority>) : population(0), factory(new CitizenFactory()), iterator(nullptr) {
    // iterator = new CitizenIterator(citizens);
    this->taxAuthority = taxAuth;
}

DepartmentOfHomeAffairs::~DepartmentOfHomeAffairs() {
    delete factory;
    delete iterator;

    for (Citizen* citizen : citizens) {
        delete citizen;
    }
    citizens.clear();
}

void DepartmentOfHomeAffairs::registerBirth() {
    std::string type = "worker";
    int startingSatisfaction = 100;
    int startingFunds = 1000;

    Citizen* newCitizen = factory->createCitizen(type, startingSatisfaction, startingFunds);

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

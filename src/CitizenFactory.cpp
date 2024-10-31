#include "CitizenFactory.h"
#include <iostream>

CitizenFactory::CitizenFactory(TaxAuthority* taxAuthority) {
    taxAuthority = taxAuthority;
    std::string type = "citizen";
}

Citizen* CitizenFactory::createCitizen(std::string& type, int startingSatisfaction, int startingFunds) {
    int id = citizenCount;
    this->citizenCount++;
    return new Citizen(id,type, startingSatisfaction, startingFunds, this->taxAuthority);
}

#include "CitizenFactory.h"
#include <iostream>

CitizenFactory::CitizenFactory(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority){}


Citizen* CitizenFactory::createCitizen(CitizenType type, int startingSatisfaction, int startingFunds) {
    int id = citizenCount;
    citizenCount++;

    Citizen * newCitizen = new Citizen(id,type, startingSatisfaction, startingFunds, taxAuthority);

    taxAuthority->registerCitizen(*newCitizen);

    return newCitizen;
}

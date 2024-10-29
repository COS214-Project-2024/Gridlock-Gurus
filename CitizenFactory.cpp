#include "CitizenFactory.h"
#include <iostream>

CitizenFactory::CitizenFactory(std::weak_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {}

Citizen* CitizenFactory::createCitizen(std::string type, int startingSatisfaction, int startingFunds) {
    std::cout << "New citizen has arrived.\n";

    Citizen* newCitizen = new Citizen(type, startingSatisfaction, startingFunds,taxAuthority);
    this->citizen = newCitizen;
    
    std::cout << "Citizen " + newCitizen->getName() + " has been registered\n";
    return newCitizen;
}

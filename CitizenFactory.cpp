#include "CitizenFactory.h"
#include <iostream>

using namespace std;

CitizenFactory::CitizenFactory() {}

Citizen* CitizenFactory::createCitizen(string type, int startingSatisfaction, int startingFunds) {
    cout << "New citizen has arrived.\n";

    Citizen* newCitizen = new Citizen(type, startingSatisfaction, startingFunds);
    this->citizen = newCitizen;
    
    cout << "Citizen " + newCitizen->getName() + " has been registered\n";
    return newCitizen;
}

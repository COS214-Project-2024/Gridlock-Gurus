#include "CitizenFactory.h"
#include <iostream>

/**
 * @brief Constructs a CitizenFactory with a reference to the TaxAuthority.
 * @param taxAuthority Shared pointer to the TaxAuthority.
 */
CitizenFactory::CitizenFactory(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority){}


/**
 * @brief Creates a Citizen with the specified type and initial attributes.
 * @param type Type of citizen to create.
 * @param startingSatisfaction Initial satisfaction level.
 * @param startingFunds Initial funds available to the citizen.
 * @return Pointer to the newly created Citizen.
 */
Citizen* CitizenFactory::createCitizen(CitizenType type, int startingSatisfaction, int startingFunds) {
    int id = citizenCount;
    citizenCount++;

    Citizen * newCitizen = new Citizen(id,type, startingSatisfaction, startingFunds, taxAuthority);

    taxAuthority->registerCitizen(*newCitizen);

    return newCitizen;
}

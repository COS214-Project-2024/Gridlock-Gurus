#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include <memory>
#include "Citizen.h"
#include "CitizenType.h"

/**
 * @brief Factory class for creating Citizen instances.
 */
class CitizenFactory {
private:
    std::shared_ptr<TaxAuthority> taxAuthority;
    int citizenCount = 0;

public:
    /**
     * @brief Constructs a CitizenFactory with a specified tax authority.
     * @param taxAuthority Shared pointer to the tax authority.
     */
    CitizenFactory(std::shared_ptr<TaxAuthority> taxAuthority);

    /**
     * @brief Default destructor for the CitizenFactory class.
     */
    ~CitizenFactory() = default;

    /**
     * @brief Creates a new Citizen with specified attributes.
     * @param type Type of citizen.
     * @param startingSatisfaction Initial satisfaction level.
     * @param startingFunds Initial funds for the citizen.
     * @return Pointer to the newly created Citizen.
     */
    Citizen* createCitizen(CitizenType type, int startingSatisfaction, int startingFunds);
};

#endif // CITIZENFACTORY_H

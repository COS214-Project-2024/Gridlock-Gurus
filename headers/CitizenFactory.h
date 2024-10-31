#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include <memory>
#include "Citizen.h"

/**
 * @brief Factory class to create Citizen objects.
 *
 * This class provides methods to create instances of Citizen with specific attributes.
 */
class CitizenFactory {
private:
    std::shared_ptr<TaxAuthority> taxAuthority;
    int citizenCount = 0;

public:
    /**
     * @brief Construct a new CitizenFactory object.
     *
     * Initializes the CitizenFactory with default values.
     */
    CitizenFactory(std::shared_ptr<TaxAuthority> taxAuthority);

    /**
     * @brief Destroy the CitizenFactory object.
     *
     * Cleans up any resources used by the factory.
     */
     ~CitizenFactory() = default;

    /**
     * @brief Creates a new Citizen object.
     *
     * @param type The type of citizen to create.
     * @param startingSatisfaction The initial satisfaction level of the citizen.
     * @param startingFunds The initial funds available to the citizen.
     * @return Pointer to the newly created Citizen object.
     */
    Citizen* createCitizen(std::string& type, int startingSatisfaction, int startingFunds);
};

#endif // CITIZENFACTORY_H

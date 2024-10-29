#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include "Citizen.h"

/**
 * @brief Factory class to create Citizen objects.
 *
 * This class provides methods to create instances of Citizen with specific attributes.
 */
class CitizenFactory {
private:
    Citizen* citizen;

public:
    /**
     * @brief Construct a new CitizenFactory object.
     *
     * Initializes the CitizenFactory with default values.
     */
    CitizenFactory();

    /**
     * @brief Destroy the CitizenFactory object.
     *
     * Cleans up any resources used by the factory.
     */
    virtual ~CitizenFactory();

    /**
     * @brief Creates a new Citizen object.
     *
     * @param type The type of citizen to create.
     * @param startingSatisfaction The initial satisfaction level of the citizen.
     * @param startingFunds The initial funds available to the citizen.
     * @return Pointer to the newly created Citizen object.
     */
    Citizen* createCitizen(std::string type, int startingSatisfaction, int startingFunds);
};

#endif // CITIZENFACTORY_H
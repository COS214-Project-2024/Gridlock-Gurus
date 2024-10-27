#ifndef CITY_H
#define CITY_H

#include "Government.h"
#include "BuildingCollection.h"

/**
 * @brief Represents the entire city, managing citizens, buildings, and services.
 *
 * Subject in the Observer pattern, notifying its observers (Government) about changes in the state.
 */
class City {
private:
    Government *government; ///< Pointer to the government managing the city.
    BuildingCollection *buildings; ///< Pointer to the city's BuildingCollection.
    std::vector<Citizen> observingCitizens;
    int citizenSatisfaction; ///< The overall satisfaction level of citizens.

public:
    /**
     * @brief Constructs a new City object.
     *
     * @param government A pointer to the Government object associated with this City.
     * @param buildings A pointer to the BuildingCollection containing the buildings in this City.
     * @param citizenSatisfaction An optional integer representing the initial satisfaction of the citizens, defaulting to MAX 100.
     */
    City(Government *government, BuildingCollection *buildings, int citizenSatisfaction = 100);

    /**
     * @brief Destroys the City object.
     */
    virtual ~City();

    /**
     * @brief Adds an observer (Citizen) to the city.
     * @param observer The citizen to be added.
     */
    void addObserver(const Citizen &observer);

    /**
     * @brief Removes an observer (Citizen) from the city.
     * @param observer The citizen to be removed.
     */
    void removeObserver(const Citizen &observer);

    /**
     * @brief Notifies all observers of a change in the city's state.
     *
     * Observer pattern -> updating observers when the city's state changes.
     */
    void notifyObservers();

    /**
     * @brief Adds a new building to the city's collection of buildings.
     */
    void addBuilding(Building *building) const;

    /**
     * @brief Updates citizen satisfaction based on city conditions.
     */
    void calcOverallCitizenSatisfaction();

    /**
     * @brief Sets the state of citizen satisfaction in the city.
     * @param citizenSatisfaction The new citizen satisfaction level.
     */
    void setState(int citizenSatisfaction);

    /**
     * @brief Gets the current state of citizen satisfaction in the city.
     * @return The current citizen satisfaction level.
     */
    int getState() const;
};

#endif // CITY_H

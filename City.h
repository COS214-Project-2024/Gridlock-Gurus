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
    Government* government;  ///< Pointer to the government managing the city.
    BuildingCollection* buildings;  ///< Collection of buildings in the city.
    int citizenHappiness;  ///< The overall happiness level of citizens.

public:
    /**
     * @brief Constructs a new City object.
     */
    City();
    
    /**
     * @brief Destroys the City object.
     */
    virtual ~City();

    /**
     * @brief Adds an observer (Government) to the city.
     * @param observer The observer to be added.
     */
    void addObserver(Government* observer);

    /**
     * @brief Removes an observer (Government) from the city.
     * @param observer The observer to be removed.
     */
    void removeObserver(Government* observer);

    /**
     * @brief Notifies all observers of a change in the city's state.
     *
     * Observer pattern -> updating observers when the city's state changes.
     */
    void notifyObservers();

    /**
     * @brief Adds a new building to the city's collection of buildings.
     */
    void addBuilding();

    /**
     * @brief Updates citizen happiness based on city conditions.
     */
    void citizenHappiness();

    /**
     * @brief Sets the state of citizen happiness in the city.
     * @param citizenHappiness The new citizen happiness level.
     */
    void setState(int citizenHappiness);

    /**
     * @brief Gets the current state of citizen happiness in the city.
     * @return The current citizen happiness level.
     */
    int getState() const;
};

#endif // CITY_H
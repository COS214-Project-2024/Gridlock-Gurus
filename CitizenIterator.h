#ifndef CITIZENITERATOR_H
#define CITIZENITERATOR_H

#include "Citizen.h"

/**
 * @brief Iterator class to iterate over citizens.
 *
 * The CitizenIterator class provides functionality to traverse through a collection
 * of Citizen objects, allowing for easy access to each citizen in a sequential manner.
 */
class CitizenIterator {
public:
    /**
     * @brief Construct a new CitizenIterator object.
     *
     * Initializes the iterator for traversing the collection of citizens.
     */
    CitizenIterator();

    /**
     * @brief Destroy the CitizenIterator object.
     *
     * Cleans up resources used by the iterator.
     */
    virtual ~CitizenIterator();

    /**
     * @brief Checks if there are more citizens to iterate over.
     *
     * @return true if there is at least one more citizen to iterate over; false otherwise.
     */
    bool hasNext();

    /**
     * @brief Retrieves the next citizen in the iteration.
     *
     * @return Pointer to the next Citizen object in the collection.
     * 
     * @note This function should be called only if hasNext() returns true; otherwise, 
     * it may lead to undefined behavior.
     */
    Citizen* next();
};

#endif // CITIZENITERATOR_H
 

#ifndef TAXI_H
#define TAXI_H

#include "Vehicle.h"

/**
 * @class Taxi
 * @brief Concrete class representing a taxi in the transportation system.
 * 
 * The `Taxi` class implements the behavior of a taxi vehicle, which is responsible for 
 * transporting passengers. It defines the collection, offloading, and other 
 * taxi-specific operations.
 */
class Taxi : public Vehicle {
public:
    /**
     * @brief Constructor for the Taxi class.
     *
     * Initializes the taxi with default values.
     */
    Taxi();

    /**
     * @brief Destructor for the Taxi class.
     *
     * Ensures proper cleanup of resources associated with the taxi.
     */
    virtual ~Taxi();

    /**
     * @brief Collects a specified amount of passengers.
     *
     * This method simulates the loading of passengers into the taxi.
     * 
     * @param amount The number of passengers to collect.
     */
    void collect(int amount) override;

    /**
     * @brief Offloads a specified amount of passengers.
     *
     * This method simulates the unloading of passengers from the taxi.
     * 
     * @param amount The number of passengers to offload.
     */
    void offload(int amount) override;

    /**
     * @brief Runs the taxi.
     *
     * This method simulates the taxi moving to a destination.
     */
    void run() override;

    /**
     * @brief Simulates a taxi breakdown.
     *
     * This method transitions the taxi into a broken or damaged state.
     */
    void breakDown() override;

    /**
     * @brief Delays the taxi's operation.
     *
     * This method simulates a delay in the taxi's journey or operation.
     */
    void delay() override;

    /**
     * @brief Clones the taxi.
     *
     * Creates a copy of the taxi object.
     */
    void clone() override;
};

#endif // TAXI_H

#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

/**
 * @class Truck
 * @brief Concrete class representing a truck in the transportation system.
 * 
 * The `Truck` class implements the behavior of a truck vehicle, which is responsible for 
 * transporting goods or passengers. It defines the collection, offloading, and other 
 * vehicle-specific operations.
 */
class Truck : public Vehicle {
public:
    /**
     * @brief Constructor for the Truck class.
     *
     * Initializes the truck with default values.
     */
    Truck();

    /**
     * @brief Destructor for the Truck class.
     *
     * Ensures proper cleanup of resources associated with the truck.
     */
    virtual ~Truck();

    /**
     * @brief Collects a specified amount of cargo or passengers.
     *
     * This method simulates the loading of cargo or passengers onto the truck.
     * 
     * @param amount The amount to collect (e.g., cargo weight or number of passengers).
     */
    void collect(int amount) override;

    /**
     * @brief Offloads a specified amount of cargo or passengers.
     *
     * This method simulates the unloading of cargo or passengers from the truck.
     * 
     * @param amount The amount to offload (e.g., cargo weight or number of passengers).
     */
    void offload(int amount) override;

    /**
     * @brief Runs the truck.
     *
     * This method simulates the truck moving to a destination.
     */
    void run() override;

    /**
     * @brief Simulates a truck breakdown.
     *
     * This method transitions the truck into a broken or damaged state.
     */
    void breakDown() override;

    /**
     * @brief Delays the truck's operation.
     *
     * This method simulates a delay in the truck's journey or operation.
     */
    void delay() override;

    /**
     * @brief Clones the truck.
     *
     * Creates a copy of the truck object.
     */
    void clone() override;
};

#endif // TRUCK_H

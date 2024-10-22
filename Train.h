#ifndef TRAIN_H
#define TRAIN_H

#include "Vehicle.h"

/**
 * @class Train
 * @brief Concrete class representing a train in the transportation system.
 */
class Train : public Vehicle {
public:
    /**
     * @brief Constructor for the Train class.
     *
     * Initializes the train with default values.
     */
    Train();

    /**
     * @brief Destructor for the Train class.
     *
     * Ensures proper cleanup of resources associated with the train.
     */
    virtual ~Train();

    /**
     * @brief Collects a specified amount of cargo or passengers.
     *
     * This method simulates the loading of cargo or passengers onto the train.
     * 
     * @param amount The amount to collect (e.g., cargo weight or number of passengers).
     */
    void collect(int amount) override;

    /**
     * @brief Offloads a specified amount of cargo or passengers.
     *
     * This method simulates the unloading of cargo or passengers from the train.
     * 
     * @param amount The amount to offload (e.g., cargo weight or number of passengers).
     */
    void offload(int amount) override;

    /**
     * @brief Runs the train.
     *
     * This method simulates the train moving to a destination.
     */
    void run() override;

    /**
     * @brief Simulates a train breakdown.
     *
     * This method transitions the train into a broken or damaged state.
     */
    void breakDown() override;

    /**
     * @brief Delays the train's operation.
     *
     * This method simulates a delay in the train's journey or operation.
     */
    void delay() override;

    /**
     * @brief Clones the train.
     *
     * Creates a copy of the train object.
     */
    void clone() override;

};

#endif // TRAIN_H

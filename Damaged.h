#ifndef DAMAGED_H
#define DAMAGED_H

#include "TransportState.h"

/**
 * @class Damage
 * @brief Represents a damage state of a vehicle in the transport system.
 */
class Damaged : public TransportState {
public:
    /**
     * @brief Constructor for the Damaged state.
     *
     * Initializes the state of the vehicle as "damaged".
     */
    Damaged();

    /**
     * @brief Destructor for the Damaged state.
     *
     * Cleans up any resources associated with the damaged state.
     */
    ~Damaged();

    /**
     * @brief Returns the current state of the vehicle.
     *
     * @return A `TransportState` object representing the current state of the vehicle.
     */
    TransportState returnState() override;

    /**
     * @brief Simulates breaking the vehicle.
     *
     * This method would trigger the transition of the vehicle to the damaged state.
     */
    void breakTransport() override;

    /**
     * @brief Repairs the vehicle.
     *
     * This method would trigger the transition of the vehicle out of the damaged state, 
     * making it functional again.
     */
    void repair() override;
};

#endif // DAMAGED_H

#ifndef DAMAGED_H
#define DAMAGED_H

#include "TransportState.h"

/**
 * @class Damage
 * @brief Represents a damage state of a vehicle in the transport system.
 * 
 * The `Damage` class models the state of a vehicle that is no longer fully functional. 
 * This state could be transitioned into after some damage from breaking. 
 * Vehicles in this state need repair before they can become fully functional again.
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
    virtual ~Damaged();

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

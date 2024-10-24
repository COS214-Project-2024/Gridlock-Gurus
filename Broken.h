#ifndef BROKEN_H
#define BROKEN_H

#include "TransportState.h"

/**
 * @class Broken
 * @brief Represents a broken state of a vehicle in the transport system.
 * 
 * The `Broken` class models the state of a vehicle that is no longer functional. 
 * This state could be transitioned into after some damage from breaking. 
 * Vehicles in this state need repair before they can become functional again.
 */
class Broken : public TransportState {
public:
    /**
     * @brief Constructor for the Broken state.
     *
     * Initializes the state of the vehicle as "broken".
     */
    Broken();

    /**
     * @brief Destructor for the Broken state.
     *
     * Cleans up any resources associated with the broken state.
     */
    virtual ~Broken();

    /**
     * @brief Returns the current state of the vehicle.
     *
     * @return A `TransportState` object representing the current state of the vehicle.
     */
    TransportState returnState() override;

    /**
     * @brief Simulates breaking the vehicle.
     *
     * This method would trigger the transition of the vehicle to the broken state.
     */
    void breakTransport() override;

    /**
     * @brief Repairs the vehicle.
     *
     * This method would trigger the transition of the vehicle out of the broken state, 
     * making it functional again.
     */
    void repair() override;
};

#endif // BROKEN_H
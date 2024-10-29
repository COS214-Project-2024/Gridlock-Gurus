#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "TransportState.h"

/**
 * @class Functional
 * @brief Represents a functional state of a vehicle in the transport system.
 * 
 * The `Functional` class models the state of a vehicle that is not damaged.
 * This state could be transitioned into after repairing from Damaged or Broken states. 
 * Vehicles in this state can take damage to become Damaged.
 */
class Functional : public TransportState {
public:
    /**
     * @brief Constructor for the Functional state.
     *
     * Initializes the state of the vehicle as "functional".
     */
    Functional();

    /**
     * @brief Destructor for the Functional state.
     *
     * Cleans up any resources associated with the functional state.
     */
    virtual ~Functional();

    /**
     * @brief Returns the current state of the vehicle.
     *
     * @return A `TransportState` object representing the current state of the vehicle.
     */
    TransportState* returnState() override;

    /**
     * @brief Simulates breaking the vehicle.
     *
     * This method would trigger the transition of the vehicle to the functional state.
     */
    void breakTransport() override;

    /**
     * @brief Repairs the vehicle.
     *
     * This method would trigger the transition of the vehicle out of the functional state, 
     * making it functional again.
     */
    void repair() override;
};

#endif // FUNCTIONAL_H

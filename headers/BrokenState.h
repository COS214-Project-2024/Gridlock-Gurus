#ifndef BROKENSTATE_H
#define BROKENSTATE_H

#include "TransportState.h"
#include "Vehicle.h"

/**
 * @class BrokenState
 * @brief Represents the broken state of a vehicle, inherited from TransportState.
 */
class BrokenState : public TransportState {
public:
    /**
     * @brief Default constructor for the BrokenState class.
     */
    BrokenState() = default;

    /**
     * @brief Default destructor for the BrokenState class.
     */
    ~BrokenState() = default;

    /**
     * @brief Attempts to run the vehicle in the broken state.
     * @return true if the vehicle can still perform some action, false otherwise.
     */
    bool run();
};

#endif // BROKENSTATE_H

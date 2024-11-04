#ifndef FUNCTIONALSTATE_H
#define FUNCTIONALSTATE_H

#include "TransportState.h"
#include "Vehicle.h"

/**
 * @class FunctionalState
 * @brief Class representing a functional state of a transport vehicle.
 */
class FunctionalState : public TransportState {
public:
    /** 
     * @brief Default constructor for FunctionalState.
     */
    FunctionalState() = default;

    /** 
     * @brief Default destructor for FunctionalState.
     */
    ~FunctionalState() = default;

    /**
     * @brief Run the vehicle in the functional state.
     * @return True if the vehicle runs successfully; otherwise false.
     */
    bool run();
};

#endif //FUNCTIONALSTATE_H

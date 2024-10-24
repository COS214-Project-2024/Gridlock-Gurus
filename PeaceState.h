#ifndef PEACESTATE_H
#define PEACESTATE_H

#include "PoliceState.h"

/**
 * @brief Represents a state of peace in the city.
 *
 * ConcreteState in the State pattern. It extends the PoliceState class and provides an implementation for checking the operational status of police services during peaceful conditions.
 */
class PeaceState : public PoliceState {
public:
    /**
     * @brief Constructs a new PeaceState object.
     */
    PeaceState();

    /**
     * @brief Destroys the PeaceState object.
     */
    virtual ~PeaceState();

    /**
     * @brief Checks the operational status of the police service during a state of peace.
     * This method implements behavior specific to the peaceful state.
     */
    void checkOperation() override;
};

#endif // PEACESTATE_H

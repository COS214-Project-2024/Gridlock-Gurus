#ifndef UNRESTSTATE_H
#define UNRESTSTATE_H

#include "PoliceState.h"

/**
 * @brief Represents a state of unrest in the city.
 *
 * ConcreteState in the State pattern. It extends the PoliceState class and provides an implementation for checking the operational status of police services during times of unrest.
 */
class UnrestState : public PoliceState {
public:
    /**
     * @brief Constructs a new UnrestState object.
     */
    UnrestState();

    /**
     * @brief Destroys the UnrestState object.
     */
    virtual ~UnrestState();

    /**
     * @brief Checks the operational status of the police service during a state of unrest.
     * This method implements behavior specific to the unrest state.
     */
    void checkOperation() override;
};

#endif // UNRESTSTATE_H

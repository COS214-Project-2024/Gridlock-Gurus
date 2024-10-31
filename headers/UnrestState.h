#ifndef UNRESTSTATE_H
#define UNRESTSTATE_H

#include "PoliceService.h"
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
    UnrestState(PoliceService& service) : PoliceState(service) {}

    /**
     * @brief Destroys the UnrestState object.
     */
    ~UnrestState() = default;

    /**
     * @brief Checks the operational status of the police service during a state of unrest.
     * This method implements behavior specific to the unrest state.
     */
    void checkOperation() override;
    std::string getName() override;
};

#endif // UNRESTSTATE_H

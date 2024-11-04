#ifndef UNRESTSTATE_H
#define UNRESTSTATE_H

#include "PoliceService.h"
#include "PoliceState.h"

/**
 * @class UnrestState
 * @brief Represents the state of unrest in the police service.
 */
class UnrestState : public PoliceState {
public:
    /**
     * @brief Constructs a new UnrestState object.
     * @param service Reference to the police service.
     */
    UnrestState(PoliceService& service) : PoliceState(service) {}

    /**
     * @brief Destroys the UnrestState object.
     */
    ~UnrestState() = default;

    /**
     * @brief Checks the operational status during unrest.
     */
    void checkOperation() override;

    /**
     * @brief Gets the name of the current state.
     * @return The name of the state.
     */
    std::string getName() override;
};

#endif // UNRESTSTATE_H
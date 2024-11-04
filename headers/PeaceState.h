#ifndef PEACESTATE_H
#define PEACESTATE_H

#include "PoliceState.h"
#include "PoliceService.h"

/**
 * @class PeaceState
 * @brief Represents the 'Peace' state of the police service.
 */
class PeaceState : public PoliceState {
private:
    PoliceService* service;

public:
    /**
     * @brief Constructs a PeaceState.
     * @param service Reference to the associated PoliceService.
     */
    PeaceState(PoliceService& service) : PoliceState(service) {}

    /**
     * @brief Destructor for PeaceState.
     */
    ~PeaceState() override = default;

    /**
     * @brief Checks the operation status in the Peace state.
     */
    void checkOperation() override;

    /**
     * @brief Gets the name of the Peace state.
     * @return The name of the state.
     */
    std::string getName() override;
};

#endif // PEACESTATE_H

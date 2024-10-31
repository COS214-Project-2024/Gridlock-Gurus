#ifndef PEACESTATE_H
#define PEACESTATE_H

#include "PoliceState.h"
#include "PoliceService.h"


/**
 * @brief Represents a state of peace in the city.
 *
 * ConcreteState in the State pattern. It extends the PoliceState class and provides an implementation for checking the operational status of police services during peaceful conditions.
 */
class PeaceState : public PoliceState {
private:
 PoliceService* service;
public:
    /**
     * @brief Constructs a new PeaceState object.
     */
    PeaceState(PoliceService& service) : PoliceState(service) {}

    /**
     * @brief Destroys the PeaceState object.
     */
    ~PeaceState()override = default;

    /**
     * @brief Checks the operational status of the police service during a state of peace.
     * This method implements behavior specific to the peaceful state.
     */
    void checkOperation() override;
    std::string getName() override;
};

#endif // PEACESTATE_H

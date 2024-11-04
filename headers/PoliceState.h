#ifndef POLICESTATE_H
#define POLICESTATE_H

#include <string>
#include <iostream>
#include "PoliceService.h"

class PoliceService;

/**
 * @class PoliceState
 * @brief Abstract class representing the state of a police service.
 */
class PoliceState {
protected:
    PoliceService& service;

public:
    /**
     * @brief Constructs a PoliceState.
     * @param service Reference to the associated PoliceService.
     */
    PoliceState(PoliceService& service) : service(service) {}

    /**
     * @brief Virtual destructor for PoliceState.
     */
    virtual ~PoliceState() = default;

    /**
     * @brief Checks the operation status of the police service.
     */
    virtual void checkOperation() = 0;

    /**
     * @brief Gets the name of the current police state.
     * @return The name of the state.
     */
    virtual std::string getName() = 0;
};

#endif // POLICESTATE_H

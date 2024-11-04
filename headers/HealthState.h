#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

#include <string>
#include <iostream>
#include "HealthService.h"

class HealthService;

/**
 * @class HealthState
 * @brief Abstract base class representing a state of the health service.
 */
class HealthState {
protected:
    HealthService& service;
public:
    /**
     * @brief Constructs a HealthState.
     * @param service Reference to the associated HealthService.
     */
    HealthState(HealthService& service) : service(service) {}

    /**
     * @brief Virtual destructor for HealthState.
     */
    virtual ~HealthState() = default;

    /**
     * @brief Gets the health status of the current state.
     * @return The health status as a string.
     */
    virtual std::string getHealthStatus() = 0;

    /**
     * @brief Gets the quality of time spent in the health service.
     * @return The quality of time as an integer.
     */
    virtual int getQualityOfTime() = 0;

    /**
     * @brief Gets the name of the current health state.
     * @return The name of the state.
     */
    virtual std::string getName() = 0;
};

#endif // HEALTHSTATE_H

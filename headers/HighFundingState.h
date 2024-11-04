#ifndef HIGHFUNDINGSTATE_H
#define HIGHFUNDINGSTATE_H

#include "HealthService.h"
#include "HealthState.h"
#include <string>

/**
 * @class HighFundingState
 * @brief Represents a state of high funding for the health service.
 */
class HighFundingState : public HealthState {
public:
    /**
     * @brief Constructs a HighFundingState.
     * @param service Reference to the associated HealthService.
     */
    HighFundingState(HealthService& service) : HealthState(service) {}

    /**
     * @brief Destructor for HighFundingState.
     */
    ~HighFundingState() override = default;

    /**
     * @brief Gets the health status in the high funding state.
     * @return The health status as a string.
     */
    std::string getHealthStatus() override;

    /**
     * @brief Gets the quality of time spent in the health service.
     * @return The quality of time as an integer.
     */
    int getQualityOfTime() override;

    /**
     * @brief Gets the name of the high funding state.
     * @return The name of the state.
     */
    std::string getName() override;
};

#endif // HIGHFUNDINGSTATE_H

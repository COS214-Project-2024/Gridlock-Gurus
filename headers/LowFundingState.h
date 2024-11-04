#ifndef LOWFUNDINGSTATE_H
#define LOWFUNDINGSTATE_H

#include "HealthService.h"
#include "HealthState.h"
#include <string>

/**
 * @class LowFundingState
 * @brief Represents a state of low funding for the health service.
 */
class LowFundingState : public HealthState {
public:
    /**
     * @brief Constructs a LowFundingState.
     * @param service Reference to the associated HealthService.
     */
    LowFundingState(HealthService& service) : HealthState(service) {}

    /**
     * @brief Destructor for LowFundingState.
     */
    ~LowFundingState()override = default;

    /**
     * @brief Gets the health status in the low funding state.
     * @return The health status as a string.
     */
    std::string getHealthStatus() override;

    /**
     * @brief Gets the quality of time spent in the health service.
     * @return The quality of time as an integer.
     */
    int getQualityOfTime() override;

    /**
     * @brief Gets the name of the low funding state.
     * @return The name of the state.
     */
    std::string getName() override;
};

#endif // LOWFUNDINGSTATE_H

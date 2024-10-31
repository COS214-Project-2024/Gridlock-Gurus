#ifndef LOWFUNDINGSTATE_H
#define LOWFUNDINGSTATE_H

#include "HealthService.h"
#include "HealthState.h"
#include <string>
/**
 * @brief Represents a low-funding state for health services.
 *
 * ConcreteState in the State pattern. It extends the HealthState class and implements the methods to manage health service operations when funding is low.
 */
class LowFundingState : public HealthState {
public:
    /**
     * @brief Constructs a new LowFundingState object.
     */
    LowFundingState(HealthService& service) : HealthState(service) {}

    /**
     * @brief Destroys the LowFundingState object.
     */
     ~LowFundingState()override = default;

    /**
     * @brief Retrieves the current health status of the services in a low-funding state.
     * This method implements behavior specific to the low-funding condition.
     */
    std::string getHealthStatus() override;

    /**
     * @brief Gets the quality of service time in a low-funding state.
     * @return int The quality level of service time.
     */
    int getQualityOfTime() override;
    std::string getName() override;
};

#endif // LOWFUNDINGSTATE_H

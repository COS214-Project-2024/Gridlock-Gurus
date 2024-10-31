#ifndef HIGHFUNDINGSTATE_H
#define HIGHFUNDINGSTATE_H

#include "HealthService.h"
#include "HealthState.h"

/**
 * @brief Represents a high-funding state for health services.
 *
 * ConcreteState in the State pattern. It extends the HealthState class and implements the methods to manage health service operations when funding is high.
 */
class HighFundingState : public HealthState {
private:
 HealthService* service;
public:
    /**
     * @brief Constructs a new HighFundingState object.
     */
    HighFundingState();

    /**
     * @brief Destroys the HighFundingState object.
     */
    virtual ~HighFundingState() = default;

    /**
     * @brief Retrieves the current health status of the services in a high-funding state.
     * This method implements behavior specific to the high-funding condition.
     */
    string getHealthStatus() override;

    /**
     * @brief Gets the quality of service time in a high-funding state.
     * @return int The quality level of service time.
     */
    int getQualityOfTime() override;
    string getName() override;
};

#endif // HIGHFUNDINGSTATE_H

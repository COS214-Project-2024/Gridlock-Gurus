#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

/**
 * @brief Abstract class representing the state of health services.
 *
 * AbstractState in the State pattern, defining the interface for various health service states. Concrete states will implement specific behaviors for managing health service operations based on funding levels.
 */
class HealthState {
public:
    /**
     * @brief Constructs a new HealthState object.
     */
    HealthState();

    /**
     * @brief Destroys the HealthState object.
     */
    virtual ~HealthState();

    /**
     * @brief Retrieves the current health status of the services.
     * This method must be implemented by concrete states to provide specific health status information.
     */
    virtual void getHealthStatus() = 0;

    /**
     * @brief Gets the time resources are available in the current state.
     * This method must be implemented by concrete states to define how long resources will last.
     * @return int The duration of resource availability.
     */
    virtual int getResourceTime() = 0;

    /**
     * @brief Gets the quality of service time in the current state.
     * This method must be implemented by concrete states to determine the quality level of health services.
     * @return int The quality level of service time.
     */
    virtual int getQualityOfTime() = 0;
};

#endif // HEALTHSTATE_H
#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Abstract class representing the state of health services.
 *
 * AbstractState in the State pattern, defining the interface for various health service states. Concrete states will implement specific behaviors for managing health service operations based on funding levels.
 */
class HealthState {
protected:
    string name;
public:
    /**
     * @brief Constructs a new HealthState object.
     */
    HealthState();

    /**
     * @brief Destroys the HealthState object.
     */
    virtual ~HealthState() = default;

    /**
     * @brief Retrieves the current health status of the services.
     * This method must be implemented by concrete states to provide specific health status information.
     */
    virtual string getHealthStatus() = 0;

    /**
     * @brief Gets the quality of service time in the current state.
     * This method must be implemented by concrete states to determine the quality level of health services.
     * @return int The quality level of service time.
     */
    virtual int getQualityOfTime() = 0;
    virtual string getName() = 0;
};

#endif // HEALTHSTATE_H
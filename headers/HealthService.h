#ifndef HEALTHSERVICE_H
#define HEALTHSERVICE_H

#include "Service.h"
#include "HealthState.h"
#include "BuildingType.h"
#include <memory>

class HealthState;

/**
 * @class HealthService
 * @brief Represents a health service in the city simulation.
 */

enum HealthStateType{
    HighFunding,
    LowFunding
};
class HealthService : public Service {
private:
    HealthStateType state;                       ///< The current state type of the health service.
    std::unique_ptr<HealthState> healthState;    ///< Pointer to the current health state object.
    int responseTime;                            ///< The response time of the health service.
public:
    /**
     * @brief Constructs a HealthService.
     * @param name The name of the health service.
     * @param cost The construction cost of the health service.
     * @param location The location of the health service.
     * @param resources Pointer to the resources the health service uses.
     * @param size The size of the health service.
     * @param owner Reference to the owner of the health service.
     * @param type The building type.
     * @param id The unique ID of the health service.
     */
    HealthService(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner,  BuildingType type, int id);

    /**
     * @brief Destructor for HealthService.
     */
    ~HealthService() override = default;

    /**
     * @brief Sets the state of the health service.
     */
    void setState();

    /**
     * @brief Processes payment related to the health service.
     * @return The amount paid.
     */
    int pay() override;

    /**
     * @brief Decreases the response time of the health service.
     * @param by The amount to decrease the response time by.
     */
    void responseTimeDec(int by);

    /**
     * @brief Increases the response time of the health service.
     * @param by The amount to increase the response time by.
     */
    void responseTimeInc(int by);

    /**
     * @brief Gets the current response time of the health service.
     * @return The response time as an integer.
     */
    int getResponseTime() const;

    /**
     * @brief Gets the current state of the health service as a string.
     * @return The name of the current state.
     */
    std::string getState() const;
};

#endif // HEALTHSERVICE_H

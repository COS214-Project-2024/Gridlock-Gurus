#include "HealthService.h"
#include "HighFundingState.h"
#include "LowFundingState.h"

/**
 * @brief Constructs a HealthService object with the specified parameters.
 *
 * @param name The name of the health service.
 * @param cost The cost associated with the health service.
 * @param location The location of the health service.
 * @param resources Pointer to the resources required by the service.
 * @param size The size of the health service.
 * @param owner Reference to the Citizen who owns the service.
 * @param type The type of building for the service.
 * @param id The unique identifier for the health service.
 */
HealthService::HealthService(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner, BuildingType type, int id) : Service(name,cost, location, resources, size, owner, type,id){
    this->responseTime = 10;
    healthState =std::make_unique<HighFundingState>(*this);
    state = HealthStateType::HighFunding;
}

/**
 * @brief Calculates the payment required for the health service.
 *
 * @return The amount to be paid for the service.
 */
int HealthService::pay() {
    return 5000;
}

/**
 * @brief Toggles the state of the health service between high and low funding.
 */
void HealthService::setState() {
    if(state == HealthStateType::LowFunding) {
        healthState = std::make_unique<HighFundingState>(*this);
        state = HealthStateType::HighFunding;
    } else {
        healthState = std::make_unique<LowFundingState>(*this);
        state = HealthStateType::LowFunding;
    }
}

/**
 * @brief Decreases the response time of the health service by the specified amount.
 *
 * @param by The amount to decrease the response time by.
 */
void HealthService::responseTimeDec(int by) {
    responseTime -= by;
}

/**
 * @brief Increases the response time of the health service by the specified amount.
 *
 * @param by The amount to increase the response time by.
 */
void HealthService::responseTimeInc(int by) {
    responseTime += by;
}

/**
 * @brief Gets the current response time of the health service.
 *
 * @return The current response time.
 */
int HealthService::getResponseTime() const {
    return this->responseTime;
}

/**
 * @brief Gets the current state of the health service as a string.
 *
 * @return A string representing the current state ("High funding" or "Low funding").
 */
std::string HealthService::getState() const {
    if(state == HealthStateType::HighFunding) {
        return "High funding";
    } else {
        return "Low funding";
    }
}


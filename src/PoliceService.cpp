#include "PoliceService.h"
#include "PeaceState.h"
#include "UnrestState.h"

/**
 * @brief Constructs a PoliceService with initial properties and sets the default state to Peace.
 * @param name Name of the service.
 * @param cost Cost of the service.
 * @param location Location of the service.
 * @param resources Pointer to the Resources object.
 * @param size Size of the building.
 * @param owner Reference to the Citizen owner.
 * @param id Identifier of the building.
 * @param type Type of building.
 */
PoliceService::PoliceService(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id, BuildingType type) : Service(name,cost, location, resources, size, owner,type,id) {
    this->responseTime = 10;
    policeState =std::make_unique<PeaceState>(*this);
    state = PoliceStateType::Peace;
}

/**
 * @brief Calculates the pay amount for police service based on the current state.
 * @return Amount to be paid.
 */
int PoliceService::pay() {
    if(state == PoliceStateType::Peace) {
        return 3300;
    } else {
        return 3500;
    }
}

/**
 * @brief Decreases the response time by a specified amount.
 * @param by Amount by which to decrease the response time.
 */
void PoliceService::responseTimeDec(int by) {
    responseTime -= by;
}

/**
 * @brief Increases the response time by a specified amount.
 * @param by Amount by which to increase the response time.
 */
void PoliceService::responseTimeInc(int by) {
    responseTime += by;
}

/**
 * @brief Toggles the state of the police service between Peace and Unrest.
 */
void PoliceService::setState() {
    if(state == PoliceStateType::Peace) {
        policeState = std::make_unique<UnrestState>(*this);
        state = PoliceStateType::Unrest;
    } else {
        policeState = std::make_unique<PeaceState>(*this);
        state = PoliceStateType::Peace;
    }
}

/**
 * @brief Gets the current state of the police service as a string.
 * @return Current state, either "Peace" or "Unrest".
 */
std::string PoliceService::getState() const {
    if(state == PoliceStateType::Peace) {
        return "Peace";
    } else {
        return "Unrest";
    }
}

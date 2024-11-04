#include "EducationService.h"
#include "HighFundingEducationState.h"
#include "LowFundingEducationState.h"

/**
 * @brief Constructs an EducationService object.
 *
 * Initializes the EducationService with the given parameters and sets its
 * initial state to HighFundingEducation with a prestige of 0.
 *
 * @param name The name of the education service.
 * @param cost The cost associated with the education service.
 * @param location The location of the education service.
 * @param resources Pointer to the resources available for the service.
 * @param size The size of the education service.
 * @param owner Reference to the Citizen who owns the service.
 * @param id The unique identifier for the education service.
 * @param type The type of the building (Education).
 */
EducationService::EducationService(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id, BuildingType type) : Service(name,cost, location, resources, size, owner,type,id){
    this->prestige = 0;
    educationState =std::make_unique<HighFundingEducationState>(*this);
    this->state =EducationStateType::HighFundingEducation; 
}

/**
 * @brief Calculates the payment amount based on the education service's state.
 *
 * Returns the payment amount based on whether the education service is in
 * a high or low funding state.
 *
 * @return The payment amount, which is 2200 for high funding and 1100 for low funding.
 */
int EducationService::pay() {
    if(state == EducationStateType::HighFundingEducation) {
        return 2200;
    } else {
        return 1100;
    }
}

/**
 * @brief Sets the state of the education service.
 *
 * Toggles the state between high funding and low funding. It updates the
 * education state accordingly.
 */
void EducationService::setState() {
    if(state == EducationStateType::LowFundingEducation) {
        educationState = std::make_unique<HighFundingEducationState>(*this);
        state = EducationStateType::HighFundingEducation;
    } else {
        educationState = std::make_unique<LowFundingEducationState>(*this);
        state = EducationStateType::LowFundingEducation;
    }
}

/**
 * @brief Decreases the prestige of the education service.
 *
 * Reduces the prestige by the specified amount.
 *
 * @param by The amount by which to decrease prestige.
 */
void EducationService::prestigeDec(int by) {
    prestige -= by;
}

/**
 * @brief Increases the prestige of the education service.
 *
 * Increases the prestige by the specified amount.
 *
 * @param by The amount by which to increase prestige.
 */
void EducationService::prestigeInc(int by) {
    prestige += by;
}

/**
 * @brief Gets the current prestige of the education service.
 *
 * @return The current prestige value.
 */
int EducationService::getPrestige() {
    return prestige;
}

/**
 * @brief Retrieves the current state of the education service.
 *
 * Returns a string representation of the current funding state (either
 * "High Funding" or "Low Funding").
 *
 * @return A string indicating the current funding state.
 */
std::string EducationService::getState() const {
    if(state == EducationStateType::HighFundingEducation) {
        return "High Funding";
    } else {
        return "Low Funding";
    }
}

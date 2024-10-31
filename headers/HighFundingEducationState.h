#ifndef HIGHFUNDINGEDUCATIONSTATE_H
#define HIGHFUNDINGEDUCATIONSTATE_H
#include "EducationService.h"
#include "EducationState.h"
#include <string>

/**
 * @brief Represents a high-funding state for education services.
 *
 * ConcreteState in the State pattern. It extends the EducationState class and implements the methods to manage education service operations when funding is high.
 */
class HighFundingEducationState : public EducationState {
public:
    /**
     * @brief Constructs a new HighFundingEducationState object.
     */
    HighFundingEducationState(EducationService& service) : EducationState(service) {}

    /**
     * @brief Destroys the HighFundingEducationState object.
     */
    ~HighFundingEducationState()override = default;

    /**
     * @brief Checks the current state of education services in a high-funding condition.
     * This method implements behavior specific to the high-funding condition.
     */
    void checkEducationState() override;

    /**
     * @brief Gets the quality of education in a high-funding state.
     * @return int The quality level of education.
     */
    int getEducationQuality() override;
    std::string getName() override;
};

#endif // HIGHFUNDINGEDUCATIONSTATE_H

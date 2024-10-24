#ifndef HIGHFUNDINGEDUCATIONSTATE_H
#define HIGHFUNDINGEDUCATIONSTATE_H

#include "EducationState.h"

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
    HighFundingEducationState();

    /**
     * @brief Destroys the HighFundingEducationState object.
     */
    virtual ~HighFundingEducationState();

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
};

#endif // HIGHFUNDINGEDUCATIONSTATE_H
#ifndef LOWFUNDINGEDUCATIONSTATE_H
#define LOWFUNDINGEDUCATIONSTATE_H

#include "EducationService.h"
#include "EducationState.h"

/**
 * @brief Represents a low-funding state for education services.
 *
 * ConcreteState in the State pattern. It extends the EducationState class and implements the methods to manage education service operations when funding is low.
 */
class LowFundingEducationState : public EducationState {
private:
    EducationService* service;
public:
    /**
     * @brief Constructs a new LowFundingEducationState object.
     */
    LowFundingEducationState();

    /**
     * @brief Destroys the LowFundingEducationState object.
     */
    virtual ~LowFundingEducationState();

    /**
     * @brief Checks the current state of education services in a low-funding condition.
     * This method implements behavior specific to the low-funding condition.
     */
    void checkEducationState() override;

    /**
     * @brief Gets the quality of education in a low-funding state.
     * @return int The quality level of education.
     */
    int getEducationQuality() override;
    string getName() override;
};

#endif // LOWFUNDINGEDUCATIONSTATE_H
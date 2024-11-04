#ifndef HIGHFUNDINGEDUCATIONSTATE_H
#define HIGHFUNDINGEDUCATIONSTATE_H
#include "EducationService.h"
#include "EducationState.h"
#include <string>

/**
 * @class HighFundingEducationState
 * @brief Represents a state of high funding for the education service.
 */
class HighFundingEducationState : public EducationState {
public:
    /**
     * @brief Constructs a HighFundingEducationState.
     * @param service Reference to the associated EducationService.
     */
    HighFundingEducationState(EducationService& service) : EducationState(service) {}

    /**
     * @brief Destructor for HighFundingEducationState.
     */
    ~HighFundingEducationState()override = default;

    /**
     * @brief Checks the current state of the education service.
     */
    void checkEducationState() override;

    /**
     * @brief Gets the quality of education in the high funding state.
     * @return The quality of education as an integer.
     */
    int getEducationQuality() override;

    /**
     * @brief Gets the name of the high funding education state.
     * @return The name of the state.
     */
    std::string getName() override;
};

#endif // HIGHFUNDINGEDUCATIONSTATE_H

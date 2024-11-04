#ifndef LOWFUNDINGEDUCATIONSTATE_H
#define LOWFUNDINGEDUCATIONSTATE_H

#include <string>
#include "EducationService.h"
#include "EducationState.h"

/**
 * @class LowFundingEducationState
 * @brief Represents a state of low funding for the education service.
 */
class LowFundingEducationState : public EducationState {
public:
    /**
     * @brief Constructs a LowFundingEducationState.
     * @param service Reference to the associated EducationService.
     */
    LowFundingEducationState(EducationService& service) : EducationState(service) {}

    /**
     * @brief Destructor for LowFundingEducationState.
     */
    ~LowFundingEducationState() override = default;

    /**
     * @brief Checks the current state of the education service.
     */
    void checkEducationState() override;

    /**
     * @brief Gets the quality of education in the low funding state.
     * @return The quality of education as an integer.
     */
    int getEducationQuality() override;

    /**
     * @brief Gets the name of the low funding education state.
     * @return The name of the state.
     */
    std::string getName() override;
};

#endif // LOWFUNDINGEDUCATIONSTATE_H

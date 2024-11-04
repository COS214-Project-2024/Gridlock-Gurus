#ifndef LOWFUNDINGEDUCATIONSTATE_H
#define LOWFUNDINGEDUCATIONSTATE_H

#include <string>
#include "EducationService.h"
#include "EducationState.h"


class LowFundingEducationState : public EducationState {
public:
    LowFundingEducationState(EducationService& service) : EducationState(service) {}
     ~LowFundingEducationState() override = default;
    void checkEducationState() override;
    int getEducationQuality() override;
    std::string getName() override;
};

#endif // LOWFUNDINGEDUCATIONSTATE_H

#ifndef HIGHFUNDINGEDUCATIONSTATE_H
#define HIGHFUNDINGEDUCATIONSTATE_H
#include "EducationService.h"
#include "EducationState.h"
#include <string>


class HighFundingEducationState : public EducationState {
public:
    HighFundingEducationState(EducationService& service) : EducationState(service) {}
    ~HighFundingEducationState()override = default;
    void checkEducationState() override;
    int getEducationQuality() override;
    std::string getName() override;
};

#endif // HIGHFUNDINGEDUCATIONSTATE_H

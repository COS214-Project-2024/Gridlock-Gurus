#ifndef HIGHFUNDINGSTATE_H
#define HIGHFUNDINGSTATE_H

#include "HealthService.h"
#include "HealthState.h"
#include <string>
class HighFundingState : public HealthState {
public:
    HighFundingState(HealthService& service) : HealthState(service) {}
     ~HighFundingState() override = default;
    std::string getHealthStatus() override;
    int getQualityOfTime() override;
    std::string getName() override;
};

#endif // HIGHFUNDINGSTATE_H

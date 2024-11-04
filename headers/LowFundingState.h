#ifndef LOWFUNDINGSTATE_H
#define LOWFUNDINGSTATE_H

#include "HealthService.h"
#include "HealthState.h"
#include <string>
class LowFundingState : public HealthState {
public:
    LowFundingState(HealthService& service) : HealthState(service) {}
     ~LowFundingState()override = default;
    std::string getHealthStatus() override;
    int getQualityOfTime() override;
    std::string getName() override;
};

#endif // LOWFUNDINGSTATE_H

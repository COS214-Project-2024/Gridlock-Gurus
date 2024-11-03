#ifndef HEALTHSERVICE_H
#define HEALTHSERVICE_H

#include "Service.h"
#include "HealthState.h"
#include "BuildingType.h"
#include <memory>
class HealthState;

enum HealthStateType{
    HighFunding,
    LowFunding
};
class HealthService : public Service {
private:
    HealthStateType state;
    std::unique_ptr<HealthState> healthState; 
    int responseTime;
public:
    HealthService(int cost, std::string& location, Resources *resources, int size, Citizen& owner,  BuildingType name, int id);

     ~HealthService() override = default;

    void setState();
    int pay() override;

    void responseTimeDec(int by);

    void responseTimeInc(int by);

    int getResponseTime() const;

    std::string getState() const;
};

#endif // HEALTHSERVICE_H

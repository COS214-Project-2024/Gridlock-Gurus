#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

#include <string>
#include <iostream>
#include "HealthService.h"
class HealthService;
class HealthState {
protected:
    HealthService& service;
public:
    HealthState(HealthService& service) : service(service) {}

    virtual ~HealthState() = default;

    virtual std::string getHealthStatus() = 0;

    virtual int getQualityOfTime() = 0;
    virtual std::string getName() = 0;
};

#endif // HEALTHSTATE_H

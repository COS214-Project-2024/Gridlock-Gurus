#include "HealthService.h"
#include "HighFundingState.h"
#include "LowFundingState.h"

HealthService::HealthService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, BuildingType name, int id) : Service(cost, location, resources, size, owner, name,id){
    this->responseTime = 10;
    healthState =std::make_unique<HighFundingState>(*this);
    state = HealthStateType::HighFunding;
}

int HealthService::pay() {
    return 5000;
}

void HealthService::setState() {
    if(state == HealthStateType::LowFunding) {
        healthState = std::make_unique<HighFundingState>(*this);
        state = HealthStateType::HighFunding;
    } else {
        healthState = std::make_unique<LowFundingState>(*this);
        state = HealthStateType::LowFunding;
    }
}

void HealthService::responseTimeDec(int by) {
    responseTime -= by;
}

void HealthService::responseTimeInc(int by) {
    responseTime += by;
}

int HealthService::getResponseTime() const {
    return this->responseTime;
}


std::string HealthService::getState() const {
    if(state == HealthStateType::HighFunding) {
        return "High funding";
    } else {
        return "Low funding";
    }
}


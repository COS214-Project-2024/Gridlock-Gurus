#include "HealthService.h"
#include "HighFundingState.h"

HealthService::HealthService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, BuildingType name, int id) : Service(cost, location, resources, size, owner, name,id){
    this->responseTime = 10;
    healthState =std::make_unique<HighFundingState>(*this);

}

std::string HealthService::getDetails() const {
    std::string details =  "Health service: \n";
    details += "Response time: " + std::to_string(responseTime) + " minutes\n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

int HealthService::pay() {
    return 223000;
}

int HealthService::getResponseTime() {
    return responseTime;
}

void HealthService::setState() {
    /*delete state;
    state = state
    if(state->getName() == "HighFundingState") {
        benefits += 0.2;
    } else if(state->getName() == "LowFundingState") {
        benefits -= 0.2;
    }*/
}

void HealthService::responseTimeDec(int by) {
    responseTime -= by;
}

void HealthService::responseTimeInc(int by) {
    responseTime += by;
}


#include "HealthService.h"
#include "HighFundingState.h"

HealthService::HealthService(int cost, std::string location, Resources *resources, int size, Citizen& owner, TaxAuthority& taxAuthority, int id, std::string name) : Service(cost, location, resources, size, owner, taxAuthority,name,id){
    this->hospitalId = id;
    this->benefits = 1.8;
    this->maxStaff = max;
    this->currentStaff = 0;
    this->hospitalName = name;
    this->responseTime = 10;
    HealthState* highFunding = new HighFundingState();
    healthState = highFunding;
}

std::string HealthService::getDetails() const {
    std::string details =  "Health service: \n";
    details += "Hospital state: " + this->healthState->getName() + "\n";
    details += "Response time: " + std::to_string(responseTime) + " minutes\n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

int HealthService::pay() {
/*    auto it = find(staff.begin(), staff.end(), staffMember);
    if(it != staff.end()) {
        double salary;
        int amount = 223000;
        //benefits are affected by the state of education
        salary = amount*benefits;
        std::cout<< staffMember->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return salary;
    } else {
        std::cout << staffMember->getName() << "? Who the heck are you? You're not a doctor!\n";
    }*/
    return 223000;
}

int HealthService::getResponseTime() {
    return responseTime;
}

void HealthService::setState(HealthState *state) {
    healthState = state;
    if(state->getName() == "HighFundingState") {
        benefits += 0.2;
    } else if(state->getName() == "LowFundingState") {
        benefits -= 0.2;
    }
}

void HealthService::responseTimeDec(int by) {
    responseTime -= by;
}

void HealthService::responseTimeInc(int by) {
    responseTime += by;
}


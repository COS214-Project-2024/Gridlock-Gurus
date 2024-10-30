#include "LowFundingState.h"

LowFundingState::LowFundingState() : HealthState() {
    name = "LowFundingState";
}

string LowFundingState::getHealthStatus() {
    string state = "Current state: " + name + "\n";
    state += "Response time: " + to_string(service->getResponseTime()) + " minutes\n";
    return state;
}

int LowFundingState::getQualityOfTime() {
    if(service) {
        int currStaff = service->getStaff();
        int maxStaff = service->getMaxStaff();
        double ratio = static_cast<double>(currStaff) / maxStaff;
        if(ratio < 0.5) {
            cout<< "Warning hospital is understaffed for high volumes. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeInc(5);
        } else {
            cout<< "This hospital is sufficiently staffed. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeDec(2);
        }
    } else {
        cout<< "Error: this state has not been assigned.\n";
    }
}

string LowFundingState::getName() {
    return name;
}



#include "HighFundingState.h"

HighFundingState::HighFundingState() : HealthState() {
    name = "HighFundingState";
}

string HighFundingState::getHealthStatus() {
    string state = "Current state: " + name + "\n";
    state += "Response time: " + to_string(service->getResponseTime()) + " minutes\n";
    return state;
}

int HighFundingState::getQualityOfTime() {
    if(service) {
        int currStaff = service->getStaff();
        int maxStaff = service->getMaxStaff();
        double ratio = static_cast<double>(currStaff) / maxStaff;
        if(ratio < 0.5) {
            cout<< "Warning hospital is understaffed. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeInc(3);
        } else {
            cout<< "This hospital is sufficiently staffed. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeDec(2);
        }
    } else {
        cout<< "Error: this state has not been assigned.\n";
    }
}

string HighFundingState::getName() {
    return name;
}



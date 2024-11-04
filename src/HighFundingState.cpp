#include "HighFundingState.h"

/**
 * @brief Gets the health status for the high funding state.
 *
 * @return A string representing the current health status.
 */
std::string HighFundingState::getHealthStatus() {
/*    string state = "Current state: " + name + "\n";

    state += "Response time: " + to_string(service->getResponseTime()) + " minutes\n";
    return state;*/
    return "State";
}

/**
 * @brief Gets the quality of time for the health service in the high funding state.
 *
 * @return The quality of time as an integer (currently always returns 0).
 */
int HighFundingState::getQualityOfTime() {
/*    if(service) {
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
    }*/
    return 0;
}

/**
 * @brief Gets the name of the current health state.
 *
 * @return A string representing the name of the health state.
 */
std::string HighFundingState::getName() {
    return "High Funding";
}



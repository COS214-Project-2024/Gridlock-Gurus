#include "PeaceState.h"

/**
 * @brief Checks the operational state of the police service and adjusts response time based on staffing levels.
 */
void PeaceState::checkOperation() {
/*    if(service) {
        int currStaff = service->getStaff();
        int maxStaff = service->getMaxStaff();
        double ratio = static_cast<double>(currStaff) / maxStaff;
        if(ratio < 0.5) {
            cout<< "Warning police station is understaffed. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeDec(1);
        } else {
            cout<< "This station is sufficiently staffed for unrest. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeDec(3);
        }
    } else {
        cout<< "Error: this state has not been assigned.\n";
    }*/
}


/**
 * @brief Gets the name of the PeaceState.
 * @return Name of the state, "Peace State".
 */
std::string PeaceState::getName() {
    return "Peace State";
}




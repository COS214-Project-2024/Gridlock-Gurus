#include "UnrestState.h"

/**
 * @brief Checks the operational status of a service during unrest.
 *
 * If assigned, this function assesses whether a service has adequate staffing for the unrest scenario. It provides
 * warnings or adjustments to response times based on the current staffing ratio.
 */
void UnrestState::checkOperation() {
/*    if(service) {
        int currStaff = service->getStaff();
        int maxStaff = service->getMaxStaff();
        double ratio = static_cast<double>(currStaff) / maxStaff;
        if(ratio < 0.5) {
            cout<< "Warning police station is understaffed during unrest. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeInc(5);
        } else {
            cout<< "This station is sufficiently staffed for unrest. Current staff: " << currStaff << "/" << maxStaff << "\n";
            service->responseTimeInc(2);
        }
    } else {
        cout<< "Error: this state has not been assigned.\n";
    }
*/
}

/**
 * @brief Retrieves the name of the state.
 * @return A string representing the name of the unrest state.
 */
std::string UnrestState::getName() {
    return "Unrest State";
}




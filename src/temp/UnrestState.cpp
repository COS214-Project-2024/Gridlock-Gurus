#include "UnrestState.h"

UnrestState::UnrestState() {
    name = "UnrestState";
}

void UnrestState::checkOperation() {
    if(service) {
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
}

string UnrestState::getName() {
    return name;
}




#include "PoliceService.h"
#include "PeaceState.h"
#include "UnrestState.h"

PoliceService::PoliceService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id, BuildingType name) : Service(cost, location, resources, size, owner,name,id) {
    this->responseTime = 10;
    policeState = new PeaceState(*this);
}

std::string PoliceService::getDetails() const{
    std::string details =  "Police service: \n";
    details += "Response time: " + std::to_string(responseTime) + " minutes\n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

int PoliceService::pay() {
    return 33000;
}

void PoliceService::responseTimeDec(int by) {
    responseTime -= by;
}

void PoliceService::responseTimeInc(int by) {
    responseTime += by;
}

void PoliceService::checkOperation() {
/*    if(responseTime <= 10) {
        //fast response
        //check citizen satisfaction
    } else if (responseTime <= 20) {
        //slow response
        if(policeState->getName() == "UnrestState") {
            double ratio = static_cast<double>(currentStaff)/static_cast<double>(maxStaff);
            if(ratio > 0.5) {
                responseTimeInc(1);
            }
        } else {
            UnrestState* unrestState = new UnrestState();
            setState(unrestState);
        }
    }*/
}

void PoliceService::setState() {
/*    delete policeState;
    policeState = &state;*/
}


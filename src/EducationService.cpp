#include "EducationService.h"
#include "HighFundingEducationState.h"

EducationService::EducationService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id, BuildingType name) : Service(cost, location, resources, size, owner,name,id){
    this->prestige = 0;
    educationState =std::make_unique<HighFundingEducationState>(*this);
}

std::string EducationService::getDetails() const {
    std::string details =  "Health service: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

int EducationService::pay() {
   return 223000;
}

void EducationService::setState() {
/*    educationState = state;
    if(state->getName() == "HighFundingState") {
        benefits += 0.2;
    } else if(state->getName() == "LowFundingState") {
        benefits -= 0.2;
    }*/
}


void EducationService::checkOperation() {

}

void EducationService::prestigeDec(int by) {
    prestige -= by;
}

void EducationService::prestigeInc(int by) {
    prestige += by;
}

int EducationService::getPrestige() {
    return prestige;
}

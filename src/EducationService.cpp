#include "EducationService.h"
#include "HighFundingEducationState.h"
#include "LowFundingEducationState.h"

EducationService::EducationService(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id, BuildingType type) : Service(name,cost, location, resources, size, owner,type,id){
    this->prestige = 0;
    educationState =std::make_unique<HighFundingEducationState>(*this);
    this->state =EducationStateType::HighFundingEducation; 
}

int EducationService::pay() {
    if(state == EducationStateType::HighFundingEducation) {
        return 2200;
    } else {
        return 1100;
    }
}

void EducationService::setState() {
    if(state == EducationStateType::LowFundingEducation) {
        educationState = std::make_unique<HighFundingEducationState>(*this);
        state = EducationStateType::HighFundingEducation;
    } else {
        educationState = std::make_unique<LowFundingEducationState>(*this);
        state = EducationStateType::LowFundingEducation;
    }
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

std::string EducationService::getState() const {
    if(state == EducationStateType::HighFundingEducation) {
        return "High Funding";
    } else {
        return "Low Funding";
    }
}

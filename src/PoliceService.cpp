#include "PoliceService.h"
#include "PeaceState.h"
#include "UnrestState.h"

PoliceService::PoliceService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id, BuildingType name) : Service(cost, location, resources, size, owner,name,id) {
    this->responseTime = 10;
    policeState =std::make_unique<PeaceState>(*this);
    state = PoliceStateType::Peace;
}

int PoliceService::pay() {
    if(state == PoliceStateType::Peace) {
        return 3300;
    } else {
        return 3500;
    }
}

void PoliceService::responseTimeDec(int by) {
    responseTime -= by;
}

void PoliceService::responseTimeInc(int by) {
    responseTime += by;
}

void PoliceService::setState() {
    if(state == PoliceStateType::Peace) {
        policeState = std::make_unique<UnrestState>(*this);
        state = PoliceStateType::Unrest;
    } else {
        policeState = std::make_unique<PeaceState>(*this);
        state = PoliceStateType::Peace;
    }
}

std::string PoliceService::getState() const {
    if(state == PoliceStateType::Peace) {
        return "Peace";
    } else {
        return "Unrest";
    }
}

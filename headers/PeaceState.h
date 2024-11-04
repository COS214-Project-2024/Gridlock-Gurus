#ifndef PEACESTATE_H
#define PEACESTATE_H

#include "PoliceState.h"
#include "PoliceService.h"



class PeaceState : public PoliceState {
private:
 PoliceService* service;
public:
    PeaceState(PoliceService& service) : PoliceState(service) {}
    ~PeaceState()override = default;
    void checkOperation() override;
    std::string getName() override;
};

#endif // PEACESTATE_H

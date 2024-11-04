#ifndef POLICESTATE_H
#define POLICESTATE_H

#include <string>
#include <iostream>
#include "PoliceService.h"

class PoliceService;
class PoliceState {
protected:
    PoliceService& service;
public:
    PoliceState(PoliceService& service) : service(service) {}
    virtual ~PoliceState() = default;
    virtual void checkOperation() = 0;

    virtual std::string getName() = 0;
};

#endif // POLICESTATE_H

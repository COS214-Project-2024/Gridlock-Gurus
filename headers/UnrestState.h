#ifndef UNRESTSTATE_H
#define UNRESTSTATE_H

#include "PoliceService.h"
#include "PoliceState.h"

class UnrestState : public PoliceState {
public:
    UnrestState(PoliceService& service) : PoliceState(service) {}
    ~UnrestState() = default;

    void checkOperation() override;
    std::string getName() override;
};

#endif // UNRESTSTATE_H

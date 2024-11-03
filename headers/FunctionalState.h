#ifndef FUNCTIONALSTATE_H
#define FUNCTIONALSTATE_H

#include "TransportState.h"
#include "Vehicle.h"

class FunctionalState : public TransportState {
public:
    FunctionalState() = default;
    ~FunctionalState() = default;
    bool run();
};

#endif //FUNCTIONALSTATE_H

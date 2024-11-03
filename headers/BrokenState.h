#ifndef BROKENSTATE_H
#define BROKENSTATE_H

#include "TransportState.h"
#include "Vehicle.h"

class BrokenState : public TransportState {
public:
    BrokenState() = default;
    ~BrokenState() = default;

    bool run();
};

#endif //BROKENSTATE_H

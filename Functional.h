#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "TransportState.h"
#include "Vehicle.h"

class Functional : public TransportState {
public:
    void checkCapacity(Vehicle* vehicle) override;
    void breakTransport(Vehicle* vehicle) override;
    void repair(Vehicle* vehicle) override;
    TransportState* returnState() override;
};

#endif

#ifndef BROKEN_H
#define BROKEN_H

#include "TransportState.h"
#include "Vehicle.h"

class Broken : public TransportState {
public:
    void checkCapacity(Vehicle* vehicle) override;
    void breakTransport(Vehicle* vehicle) override;
    void repair(Vehicle* vehicle) override;
    TransportState* returnState() override;
};

#endif

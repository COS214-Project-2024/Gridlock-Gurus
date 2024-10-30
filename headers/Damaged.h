#ifndef DAMAGED_H
#define DAMAGED_H

#include "TransportState.h"
#include "Vehicle.h"

class Damaged : public TransportState {
public:
    void checkCapacity(Vehicle* vehicle) override;
    void breakTransport(Vehicle* vehicle) override;
    void repair(Vehicle* vehicle) override;
    TransportState* returnState() override;
};

#endif

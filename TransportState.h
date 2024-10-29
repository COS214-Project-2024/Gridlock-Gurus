#ifndef TRANSPORTSTATE_H
#define TRANSPORTSTATE_H

class Vehicle;

class TransportState {
public:
    virtual ~TransportState() = default;

    virtual void checkCapacity(Vehicle* vehicle) = 0;
    virtual void breakTransport(Vehicle* vehicle) = 0;
    virtual void repair(Vehicle* vehicle) = 0;
    virtual TransportState* returnState() = 0;
};

#endif

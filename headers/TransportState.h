#ifndef TRANSPORTSTATE_H
#define TRANSPORTSTATE_H

class Vehicle;

class TransportState {
public:
    TransportState() = default;
    virtual ~TransportState() = default;
    virtual bool run() = 0;
};

#endif

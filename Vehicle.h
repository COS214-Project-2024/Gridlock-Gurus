#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "TransportState.h"

class Vehicle {
protected:
    std::string type;
    int capacity;
    int currentPassengers;
    TransportState* state;

public:
    Vehicle(const std::string& type, int capacity);
    virtual ~Vehicle() = default;

    virtual void checkState() = 0;    
    virtual void collect(int amount) = 0; 
    virtual void run() = 0;           
    virtual void breakDown() = 0;     
    virtual void delay() = 0;         
    virtual Vehicle* clone() = 0;     

    void setState(TransportState* newState);
    TransportState* getState() const;
    std::string getType() const;

    void load(int passengers);
    void offload();
};

#endif

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "TransportState.h"
#include "TransportDepartment.h"

class TransportDepartment;

class Vehicle {
protected:
    std::string type;
    int capacity;
    int currentPassengers;
    TransportState* state;
    int usageCount;
    TransportDepartment& department;

public:
    Vehicle(const std::string& type, int capacity, TransportDepartment& transportDept);
    virtual ~Vehicle() = default;

    virtual void checkState() = 0;    
    virtual void collect(int amount) = 0; 
    virtual void run() = 0;           
    virtual void breakDown() = 0;     
    virtual void delay() = 0;         
    virtual Vehicle* clone() = 0;     

    void requestRepair();
    void updateState();
    void incrementUsage();
    void setState(TransportState* newState);
    TransportState* getState() const;
    std::string getType() const;
    void repair();

    void load(int passengers);
    void offload();
};

#endif

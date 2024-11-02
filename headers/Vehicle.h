#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "TransportState.h"
#include "TransportDepartment.h"
#include "VehicleType.h"
#include <memory>
class TransportDepartment;
class TransportState;



enum VehicleState {
    Functional,
    Broken
};

class Vehicle {
protected:
    VehicleType type;
    int capacity;
    int currentPassengers;
    std::unique_ptr<TransportState> state;
    VehicleState vehicle_state;
    int usageCount;
    TransportDepartment& department;

public:
    Vehicle(VehicleType type, int capacity, TransportDepartment& transportDept);
    ~Vehicle() = default;

    void collect(int passengers); 
    bool run();           
    void setState();
    virtual Vehicle* clone();     

    VehicleType getType() const {
        return type;
    }

    VehicleState getState() const {
        return vehicle_state;
    }

    void offload();
    void repair();
    void requestRepair();
};

#endif

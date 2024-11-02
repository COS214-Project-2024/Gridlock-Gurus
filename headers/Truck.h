#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(int capacity, TransportDepartment* department);
    void checkState() override;
    void collect(int amount) override;
    void run() override;
    void breakDown() override;
    void delay() override;
    Vehicle* clone() override;
};

#endif

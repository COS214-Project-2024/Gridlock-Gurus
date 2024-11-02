#ifndef TAXI_H
#define TAXI_H

#include "Vehicle.h"

class Taxi : public Vehicle {
public:
    Taxi(int capacity, TransportDepartment* department);

    void checkState() override;
    void collect(int amount) override;
    void run() override;
    void breakDown() override;
    void delay() override;
    Vehicle* clone() override;
    void repair();
};

#endif

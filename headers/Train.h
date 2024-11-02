#ifndef TRAIN_H
#define TRAIN_H

#include "Vehicle.h"

class Train : public Vehicle {
public:
    Train(int capacity, TransportDepartment& department);

    void checkState() override;
    void collect(int amount) override;
    void run() override;
    void breakDown() override;
    void delay() override;
    Vehicle* clone() override;
};

#endif

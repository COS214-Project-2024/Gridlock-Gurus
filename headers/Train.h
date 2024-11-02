#ifndef TRAIN_H
#define TRAIN_H

#include "Vehicle.h"

class Train : public Vehicle {
public:
    Train(int capacity,TransportDepartment& department) : Vehicle(VehicleType::Train, capacity,department) {}

    Vehicle* clone() override;
};

#endif

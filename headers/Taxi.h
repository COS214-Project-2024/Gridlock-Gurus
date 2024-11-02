#ifndef TAXI_H
#define TAXI_H

#include "Vehicle.h"

class Taxi : public Vehicle {
public:
    Taxi(int capacity,TransportDepartment& department) : Vehicle(VehicleType::Taxi, capacity,department) {}
    Vehicle* clone() override;
};

#endif

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "TransportState.h"

/**
 * @brief Concrete class representing a vehicle (e.g., train, truck, taxi).
 */
class Vehicle {
private:
    std::string type;
    int numberOfPassengers;
    int capacity;
    TransportState* transportState;

public:
    Vehicle();
    ~Vehicle();
    void collect(int amount);
    void offload(int amount);
    void run();
    void breakDown();
    void delay();
    void clone();
};

#endif // VEHICLE_H


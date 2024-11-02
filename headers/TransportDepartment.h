#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include <vector>
#include <string>
#include "Vehicle.h"
#include "VehicleType.h"
class Vehicle;

class TransportDepartment {
private:
    std::vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle& vehicle);
    void manage();
    ~TransportDepartment(); 
    Vehicle& getAvailableVehicle(VehicleType type);
    void repairVehicles(Vehicle* vehicle);
};

#endif

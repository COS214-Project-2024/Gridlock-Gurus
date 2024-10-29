#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include <vector>
#include <string>
#include "Vehicle.h"

class TransportDepartment {
private:
    std::vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* vehicle);
    void manage();
    Vehicle* getAvailableVehicle(const std::string& type);
};

#endif

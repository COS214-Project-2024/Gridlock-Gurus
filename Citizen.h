#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include "Vehicle.h"
#include "TransportDepartment.h"

class Citizen {
private:
    std::string name;
    int id;
    Vehicle* currentVehicle;

public:
    Citizen(const std::string& name, int id);

    std::string getName() const;
    int getId() const;

    void callTransport(TransportDepartment& department, const std::string& type);
    void boardVehicle(Vehicle* vehicle);
    void offloadVehicle();

    bool isInVehicle() const;
};

#endif

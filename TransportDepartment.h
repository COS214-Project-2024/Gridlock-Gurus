#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include <List>
#include <string>
#include "Vehicle.h"


class TransportDepartment {
private:
    std::list<Vehicle*> trains;
    std::list<Vehicle*> trucks;
    std::list<Vehicle*> taxis;

public:
    void callTransport();
    void addToFleet(std::string type);
    ~TransportDepartment();
};

#endif // TRANSPORTDEPARTMENT_H
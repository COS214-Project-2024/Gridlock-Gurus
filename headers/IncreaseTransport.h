#ifndef INCREASETRANSPORT_H
#define INCREASETRANSPORT_H

#include "Command.h"
#include "City.h"

class IncreaseTransport : public Command {
    City& city;
    VehicleType transportType;
public:
    IncreaseTransport(City& city, VehicleType& transportType) : city(city), transportType(transportType) {};
    ~IncreaseTransport() {};
    void execute() override;
};



#endif //INCREASETRANSPORT_H

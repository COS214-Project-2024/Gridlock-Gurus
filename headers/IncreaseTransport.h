#ifndef INCREASETRANSPORT_H
#define INCREASETRANSPORT_H

#include "Command.h"
#include "City.h"

class IncreaseTransport : public Command {
    VehicleType transportType;
public:
    IncreaseTransport(VehicleType& transportType) : transportType(transportType) {};
    ~IncreaseTransport() {};
    void execute() override;
};



#endif //INCREASETRANSPORT_H

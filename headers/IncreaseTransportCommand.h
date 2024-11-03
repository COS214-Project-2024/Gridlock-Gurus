#ifndef INCREASETRANSPORTCOMMAND_H
#define INCREASETRANSPORTCOMMAND_H
#include <memory>
#include "Command.h"
#include "City.h"
#include "VehicleType.h"

class City;

class IncreaseTransportCommand : public Command {
    VehicleType type;
public:
    /**
     * @brief Constructs a new Command object.
     */
    IncreaseTransportCommand(std::shared_ptr<City> city, VehicleType type) : Command(city) {
        this->type = type;
    }

    /**
     * @brief Destroys the Command object.
     */
     ~IncreaseTransportCommand() = default;

    /**
     * @brief Executes the command.
     */
     void execute() override {
        city->increaseTransport(type);
     }
};

#endif // INCREASETRANSPORTCOMMAND_H

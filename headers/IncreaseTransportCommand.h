#ifndef INCREASETRANSPORTCOMMAND_H
#define INCREASETRANSPORTCOMMAND_H
#include <memory>
#include "Command.h"
#include "City.h"
#include "VehicleType.h"

class City;

/**
 * @class IncreaseTransportCommand
 * @brief Command to increase the transport capacity of a city.
 */
class IncreaseTransportCommand : public Command {
    VehicleType type;
public:
    /**
     * @brief Constructs an IncreaseTransportCommand.
     * @param city Shared pointer to the City object.
     * @param type The type of vehicle to increase.
     */
    IncreaseTransportCommand(std::shared_ptr<City> city, VehicleType type) : Command(city) {
        this->type = type;
    }

    /**
     * @brief Destructor for IncreaseTransportCommand.
     */
     ~IncreaseTransportCommand() = default;

    /**
     * @brief Executes the command to increase transport.
     */
    void execute() override {
        city->increaseTransport(type);
    }
};

#endif // INCREASETRANSPORTCOMMAND_H

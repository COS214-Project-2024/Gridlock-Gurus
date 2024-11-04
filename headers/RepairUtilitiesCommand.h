#ifndef REPAIRUTILITIESCOMMAND_H
#define REPAIRUTILITIESCOMMAND_H

#include <memory>
#include "Command.h"
#include "City.h"

class City;

/**
 * @class RepairUtilitiesCommand
 * @brief Command to repair utilities in the city.
 */
class RepairUtilitiesCommand : public Command {
public:
    /**
     * @brief Constructs a new RepairUtilitiesCommand object.
     * @param city Shared pointer to the city object.
     */
    RepairUtilitiesCommand(std::shared_ptr<City> city) : Command(city) {}

    /**
     * @brief Destroys the RepairUtilitiesCommand object.
     */
    ~RepairUtilitiesCommand() = default;

    /**
     * @brief Executes the command to repair utilities.
     */
    void execute() override;
};

#endif // REPAIRUTILITIESCOMMAND_H
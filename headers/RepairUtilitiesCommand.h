#ifndef REPAIRUTILITIESCOMMAND_H
#define REPAIRUTILITIESCOMMAND_H
#include <memory>
#include "Command.h"
#include "City.h"

class City;

class RepairUtilitiesCommand : public Command {
public:
    /**
     * @brief Constructs a new Command object.
     */
    RepairUtilitiesCommand(std::shared_ptr<City> city) : Command(city) {}

    /**
     * @brief Destroys the Command object.
     */
     ~RepairUtilitiesCommand() = default;

    /**
     * @brief Executes the command.
     */
     void execute() override;
};

#endif // CHANGETAXSTRATEGYCOMMAND_H

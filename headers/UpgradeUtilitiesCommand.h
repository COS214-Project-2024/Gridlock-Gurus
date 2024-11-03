#ifndef UPGRADEUTILITIESCOMMAND_H
#define UPGRADEUTILITIESCOMMAND_H
#include <memory>
#include "Command.h"
#include "City.h"

class City;

class UpgradeUtilitiesCommand : public Command {
public:
    /**
     * @brief Constructs a new Command object.
     */
    UpgradeUtilitiesCommand(std::shared_ptr<City> city) : Command(city) {}

    /**
     * @brief Destroys the Command object.
     */
     ~UpgradeUtilitiesCommand() = default;

    /**
     * @brief Executes the command.
     */
     void execute() override {
        city->upgradeUtilities();
     }
};

#endif // CHANGETAXSTRATEGYCOMMAND_H

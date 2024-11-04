#ifndef UPGRADEUTILITIESCOMMAND_H
#define UPGRADEUTILITIESCOMMAND_H

#include <memory>
#include "Command.h"
#include "City.h"

class City;

/**
 * @class UpgradeUtilitiesCommand
 * @brief Command to upgrade utilities in a city.
 */
class UpgradeUtilitiesCommand : public Command {
public:
   /**
   * @brief Constructs a new UpgradeUtilitiesCommand object.
   * @param city Shared pointer to the city where utilities will be upgraded.
   */
   UpgradeUtilitiesCommand(std::shared_ptr<City> city) : Command(city) {}

   /**
   * @brief Destroys the UpgradeUtilitiesCommand object.
   */
   ~UpgradeUtilitiesCommand() = default;

   /**
   * @brief Executes the command to upgrade city utilities.
   */
   void execute() override {
      city->upgradeUtilities();
   }
};

#endif // UPGRADEUTILITIESCOMMAND_H
#ifndef CHANGETAXSTRATEGYCOMMAND_H
#define CHANGETAXSTRATEGYCOMMAND_H
#include <memory>
#include "Command.h"
#include "City.h"
#include "TaxStrategy.h"
#include "FlatTaxStrategy.h"
#include "ProgressiveTaxStrategy.h"

class City;

enum TaxType{
    Flat,
    Progressive
};

class ChangeTaxStrategyCommand : public Command {
    TaxType strategy;
public:
    /**
     * @brief Constructs a new Command object.
     */
    ChangeTaxStrategyCommand(std::shared_ptr<City> city, TaxType strategy) : Command(city) {
        this->strategy = strategy;
    }

    /**
     * @brief Destroys the Command object.
     */
     ~ChangeTaxStrategyCommand() = default;

    /**
     * @brief Executes the command.
     */
     void execute() override;
};

#endif // CHANGETAXSTRATEGYCOMMAND_H

#ifndef CHANGETAXSTRATEGYCOMMAND_H
#define CHANGETAXSTRATEGYCOMMAND_H
#include <memory>
#include "Command.h"
#include "City.h"
#include "TaxStrategy.h"
#include "FlatTaxStrategy.h"
#include "ProgressiveTaxStrategy.h"

/**
 * @brief Forward declaration of City class.
 */
class City;

/**
 * @brief Enumeration for different tax types.
 */
enum TaxType {
    Flat,         ///< Represents a flat tax strategy.
    Progressive   ///< Represents a progressive tax strategy.
};

/**
 * @brief Command to change the tax strategy in a city.
 */
class ChangeTaxStrategyCommand : public Command {
    TaxType strategy;

public:
    /**
     * @brief Constructor for ChangeTaxStrategyCommand.
     * @param city The city where the tax strategy will be changed.
     * @param strategy The new tax strategy to apply.
     */
    ChangeTaxStrategyCommand(std::shared_ptr<City> city, TaxType strategy) : Command(city), strategy(strategy) {}

    /**
     * @brief Default destructor.
     */
    ~ChangeTaxStrategyCommand() = default;

    /**
     * @brief Executes the command to change the tax strategy.
     */
    void execute() override;
};

#endif // CHANGETAXSTRATEGYCOMMAND_H

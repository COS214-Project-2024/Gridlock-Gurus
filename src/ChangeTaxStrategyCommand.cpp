#include "ChangeTaxStrategyCommand.h"

/**
 * @brief Executes the command to change the tax strategy.
 */
void ChangeTaxStrategyCommand::execute() {
    if(strategy == TaxType::Flat) {
        city->changeTaxStrategy(std::make_unique<FlatTaxStrategy>());
    } else {
        city->changeTaxStrategy(std::make_unique<ProgressiveTaxStrategy>());
    }
}


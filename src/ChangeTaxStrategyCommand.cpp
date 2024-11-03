#include "ChangeTaxStrategyCommand.h"

void ChangeTaxStrategyCommand::execute() {
    if(strategy == TaxType::Flat) {
        city->changeTaxStrategy(std::make_unique<FlatTaxStrategy>());
    } else {
        city->changeTaxStrategy(std::make_unique<ProgressiveTaxStrategy>());
    }
}

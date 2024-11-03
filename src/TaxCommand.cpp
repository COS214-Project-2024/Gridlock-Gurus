#include "TaxCommand.h"

void TaxCommand::execute() {
    status = EXECUTED;

    taxAuthority->setStrategy(std::move(taxStrategy));
}

void TaxCommand::undo() {
    status = UNDONE;

    // Revert to the previous tax rate
    taxAuthority->setStrategy(std::move(taxStrategy));
    //std::cout << "Reverted tax rate to " << previousTaxRate << "%" << std::endl;
}

void TaxCommand::redo() {
    status = PENDING;

    // Reapply the adjusted tax rate
   taxAuthority->setStrategy(std::move(taxStrategy));
    //std::cout << "Re-applied tax rate of " << taxRate << "%" << std::endl;
}


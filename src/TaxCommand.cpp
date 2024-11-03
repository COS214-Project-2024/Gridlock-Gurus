#include "TaxCommand.h"

void TaxCommand::execute() {
    status = EXECUTED;

    taxAuthority->setStrategy(std::move(taxStrategy));
}

void TaxCommand::undo() {
    status = UNDONE;

    taxAuthority->setStrategy(std::move(taxStrategy));
    //std::cout << "Reverted tax rate to " << previousTaxRate << "%" << std::endl;
}

void TaxCommand::redo() {
    status = PENDING;

   taxAuthority->setStrategy(std::move(taxStrategy));
    //std::cout << "Re-applied tax rate of " << taxRate << "%" << std::endl;
}


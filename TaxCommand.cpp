#include "TaxCommand.h"
#include "TaxAuthority.h"
#include <iostream>

TaxCommand::TaxCommand(TaxAuthority* taxAuthority, int taxRate)
    : taxAuthority(taxAuthority), taxRate(taxRate), previousTaxRate(0) {}

TaxCommand::~TaxCommand() {}

void TaxCommand::execute() {
    Command::execute(); // Update status

    // Store current tax rate and apply the new one
    previousTaxRate = taxAuthority->getCurrentTaxRate();
    taxAuthority->adjustTaxRate(taxRate);
    std::cout << "Adjusted tax rate to " << taxRate << "%" << std::endl;
}

void TaxCommand::undo() {
    Command::undo();  // Update status

    // Revert to the previous tax rate
    taxAuthority->adjustTaxRate(previousTaxRate);
    std::cout << "Reverted tax rate to " << previousTaxRate << "%" << std::endl;
}

void TaxCommand::redo() {
    Command::redo();  // Update status

    // Reapply the adjusted tax rate
    taxAuthority->adjustTaxRate(taxRate);
    std::cout << "Re-applied tax rate of " << taxRate << "%" << std::endl;
}

#include "TaxCommand.h"
#include "TaxAuthority.h"
#include <iostream>

TaxCommand::TaxCommand(TaxAuthority* taxAuthority, int taxRate)
    : taxAuthority(taxAuthority), taxRate(taxRate) {}

TaxCommand::~TaxCommand() {
    // Cleanup resources if necessary
}

void TaxCommand::execute() {
    taxAuthority->adjustTaxRate(taxRate);
    std::cout << "Adjusted tax rate to " << taxRate << "%" << std::endl;
}

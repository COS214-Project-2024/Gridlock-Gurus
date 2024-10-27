#include "TaxCommand.h"
#include <iostream>

TaxCommand::TaxCommand() {
    // Any initialization needed for TaxCommand
}

TaxCommand::~TaxCommand() {
    // Cleanup resources if necessary
}

void TaxCommand::execute() {
    std::cout << "Adjusting tax rates for the city." << std::endl;
}

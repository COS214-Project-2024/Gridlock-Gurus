#include "ProgressiveTaxStrategy.h"

ProgressiveTaxStrategy::ProgressiveTaxStrategy(int taxRate) : taxRate(taxRate / 100) {}

int ProgressiveTaxStrategy::calculateBuildingTax(int value) {
    int tax = 0;
    
    if (value > 30000) {
        tax += (value - 30000) * (taxRate + 0.02);
        value = 30000;
    }

    if (value > 15000) {
        tax += (value - 15000) * (taxRate + 0.01);
        value = 15000;
    }

    if (value > 5000) {
        tax += (value - 5000) * taxRate;
        value = 5000;
    }

    return tax;
}

int ProgressiveTaxStrategy::calculateCitizenTax(int earnings) {
    int tax = 0;
    
    if (earnings > 30000) {
        tax += (earnings - 30000) * (taxRate + 0.02);
        earnings = 30000;
    }

    if (earnings > 15000) {
        tax += (earnings - 15000) * (taxRate + 0.01);
        earnings = 15000;
    }

    if (earnings > 5000) {
        tax += (earnings - 5000) * taxRate;
        earnings = 5000;
    }

    return tax;
}

void ProgressiveTaxStrategy::adjustRate(int percentage){
    this->taxRate = percentage / 100;
}
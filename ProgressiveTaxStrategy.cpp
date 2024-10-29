#include "ProgressiveTaxStrategy.h"

int ProgressiveTaxStrategy::calculateBuildingTax(int value) {
        float taxRate = 0.4; // 40% tax rate for flat tax
        return (int)(value - (value * taxRate));
}

int ProgressiveTaxStrategy::calculateCitizenTax(int earnings) {
        float taxRate = 0.4; // 40% tax rate for flat tax
        return (int)(earnings - (earnings * taxRate));
}

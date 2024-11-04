#include "ProgressiveTaxStrategy.h"

int ProgressiveTaxStrategy::calculateBuildingTax(int value) {
        float taxRate = 0.4;
        return (int)(value - (value * taxRate));
}

int ProgressiveTaxStrategy::calculateCitizenTax(int earnings) {
        float taxRate = 0.4;
        return (int)(earnings - (earnings * taxRate));
}


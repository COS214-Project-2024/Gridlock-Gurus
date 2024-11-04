#include "ProgressiveTaxStrategy.h"

/**
 * @brief Calculates the building tax based on a progressive tax rate.
 * @param value The value of the building.
 * @return Tax amount after applying the progressive tax rate.
 */
int ProgressiveTaxStrategy::calculateBuildingTax(int value) {
        float taxRate = 0.4;
        return (int)(value - (value * taxRate));
}

/**
 * @brief Calculates the citizen tax based on a progressive tax rate.
 * @param earnings The earnings of the citizen.
 * @return Tax amount after applying the progressive tax rate.
 */
int ProgressiveTaxStrategy::calculateCitizenTax(int earnings) {
        float taxRate = 0.4;
        return (int)(earnings - (earnings * taxRate));
}


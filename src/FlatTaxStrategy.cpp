#include "FlatTaxStrategy.h"

/**
 * @brief Calculates the building tax based on a flat rate.
 *
 * This function returns a fixed tax amount for any building based on
 * the flat tax strategy.
 *
 * @param value The value of the building (not used in the calculation).
 * @return The flat tax amount, which is always 30.
 */
int FlatTaxStrategy::calculateBuildingTax(int value) {
    return 30;
}

/**
 * @brief Calculates the citizen tax based on a flat rate.
 *
 * This function returns a fixed tax amount for any citizen based on
 * the flat tax strategy.
 *
 * @param earnings The earnings of the citizen (not used in the calculation).
 * @return The flat tax amount, which is always 30.
 */
int FlatTaxStrategy::calculateCitizenTax(int earnings) {
    return 30;
}

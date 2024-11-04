#ifndef PROGRESSIVETAXSTRATEGY_H
#define PROGRESSIVETAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @class ProgressiveTaxStrategy
 * @brief Implements a tax strategy with progressive rates.
 */
class ProgressiveTaxStrategy : public TaxStrategy {
public:
    /**
     * @brief Default constructor for ProgressiveTaxStrategy.
     */
    ProgressiveTaxStrategy() = default;

    /**
     * @brief Default destructor for ProgressiveTaxStrategy.
     */
    ~ProgressiveTaxStrategy() = default;

    /**
     * @brief Calculates tax for a building based on its value.
     * @param value The value of the building.
     * @return The calculated tax amount.
     */
    int calculateBuildingTax(int value) override;

    /**
     * @brief Calculates tax for a citizen based on their earnings.
     * @param earnings The earnings of the citizen.
     * @return The calculated tax amount.
     */
    int calculateCitizenTax(int earnings) override;
};

#endif // PROGRESSIVETAXSTRATEGY_H

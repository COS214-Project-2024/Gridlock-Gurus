#ifndef FLATTAXSTRATEGY_H
#define FLATTAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @class FlatTaxStrategy
 * @brief Class representing a flat tax strategy.
 */

class FlatTaxStrategy : public TaxStrategy {
public:
    /** 
     * @brief Default constructor for FlatTaxStrategy.
     */
    FlatTaxStrategy() = default;

    /** 
     * @brief Default destructor for FlatTaxStrategy.
     */
    ~FlatTaxStrategy() = default;

    /**
     * @brief Calculate the tax for a building.
     * @param value The value of the building.
     * @return The calculated building tax.
     */
    int calculateBuildingTax(int value) override;

    /**
     * @brief Calculate the tax for a citizen based on their earnings.
     * @param earnings The earnings of the citizen.
     * @return The calculated citizen tax.
     */
    int calculateCitizenTax(int earnings) override;
};

#endif // FLATTAXSTRATEGY_H

#ifndef FLATTAXSTRATEGY_H
#define FLATTAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @brief Implements a flat tax strategy.
 *
 * ConcreteStrategy participant in the Strategy Design Pattern.
 */
class FlatTaxStrategy : public TaxStrategy {
public:
    /**
     * @brief Constructor for the FlatTaxStrategy.
     */
    FlatTaxStrategy();
    
    /**
     * @brief Destructor for the FlatTaxStrategy.
     */
    virtual ~FlatTaxStrategy();

    /**
     * @brief Calculates tax on a building using the flat tax strategy.
     * @param value The value of the building.
     * @return Calculated building tax.
     *
     * This function acts as the algorithm() function.
     */
    int calculateBuildingTax(int value) override;

    /**
     * @brief Calculates tax on a citizen's earnings using the flat tax strategy.
     * @param earnings The earnings of the citizen.
     * @return Calculated citizen tax.
     *
     * This function acts as the algorithm() function.
     */
    int calculateCitizenTax(int earnings) override;
};

#endif // FLATTAXSTRATEGY_H
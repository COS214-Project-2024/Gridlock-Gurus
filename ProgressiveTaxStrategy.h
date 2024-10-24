#ifndef PROGRESSIVETAXSTRATEGY_H
#define PROGRESSIVETAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @brief Implements a progressive tax strategy.
 *
 * ConcreteStrategy participant in the Strategy Design Pattern.
 */
class ProgressiveTaxStrategy : public TaxStrategy {
public:
    /**
     * @brief Constructor for the ProgressiveTaxStrategy.
     */
    ProgressiveTaxStrategy();
    
    /**
     * @brief Destructor for the ProgressiveTaxStrategy.
     */
    virtual ~ProgressiveTaxStrategy();

    /**
     * @brief Calculates tax on a building using the progressive tax strategy.
     * @param value The value of the building.
     * @return Calculated building tax.
     *
     * This function acts as the algorithm() function.
     */
    int calculateBuildingTax(int value) override;

    /**
     * @brief Calculates tax on a citizen's earnings using the progressive tax strategy.
     * @param earnings The earnings of the citizen.
     * @return Calculated citizen tax.
     *
     * This function acts as the algorithm() function.
     */
    int calculateCitizenTax(int earnings) override;
};

#endif // PROGRESSIVETAXSTRATEGY_H
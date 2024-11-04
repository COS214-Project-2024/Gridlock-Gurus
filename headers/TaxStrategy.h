#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H

/**
 * @class TaxStrategy
 * @brief Abstract base class defining tax calculation strategies.
 */
class TaxStrategy {
public:
    /**
     * @brief Constructs a new TaxStrategy object.
     */
    TaxStrategy() = default;

    /**
     * @brief Destroys the TaxStrategy object.
     */
    virtual ~TaxStrategy() = default;

    /**
     * @brief Calculates the tax for a building.
     * @param value The value of the building.
     * @return The calculated tax amount.
     */
    virtual int calculateBuildingTax(int value) = 0;

    /**
     * @brief Calculates the tax for a citizen.
     * @param earnings The earnings of the citizen.
     * @return The calculated tax amount.
     */
    virtual int calculateCitizenTax(int earnings) = 0;
};

#endif // TAXSTRATEGY_H
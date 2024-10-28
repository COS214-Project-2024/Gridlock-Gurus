#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H

/**
 * @brief Abstract strategy class for calculating taxes.
 *
 * Strategy participant in the Strategy Design Pattern.
 */
class TaxStrategy {
public:
    /**
     * @brief Constructor for the TaxStrategy.
     */
    TaxStrategy();
    
    /**
     * @brief Destructor for the TaxStrategy.
     */
    virtual ~TaxStrategy();

    /**
     * @brief Calculates tax on a building.
     * @param value The value of the building.
     * @return Calculated building tax.
     *
     * This function acts as the algorithm() function.
     */
    virtual int calculateBuildingTax(int value) = 0;

    /**
     * @brief Calculates tax on a citizen's earnings.
     * @param earnings The earnings of the citizen.
     * @return Calculated citizen tax.
     *
     * This function acts as the algorithm() function.
     */
    virtual int calculateCitizenTax(int earnings) = 0;

    /**
     * @brief Sets the tax strategy configuration.
     */
    void set();

    virtual void adjustRate(int percentage) = 0;
};

#endif // TAXSTRATEGY_H

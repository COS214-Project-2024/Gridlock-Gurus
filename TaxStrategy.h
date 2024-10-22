#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H

/**
 * @brief Abstract strategy class for calculating taxes.
 */
class TaxStrategy {
public:
    TaxStrategy();  ///< Constructor
    virtual ~TaxStrategy();  ///< Destructor
};

#endif // TAXSTRATEGY_H

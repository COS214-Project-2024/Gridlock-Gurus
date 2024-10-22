#ifndef FLATTAXSTRATEGY_H
#define FLATTAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @brief Implements a flat tax strategy.
 */
class FlatTaxStrategy : public TaxStrategy {
public:
    FlatTaxStrategy();  ///< Constructor
    ~FlatTaxStrategy();  ///< Destructor
};

#endif // FLATTAXSTRATEGY_H


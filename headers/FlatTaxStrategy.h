#ifndef FLATTAXSTRATEGY_H
#define FLATTAXSTRATEGY_H

#include "TaxStrategy.h"

class FlatTaxStrategy : public TaxStrategy {
public:
    FlatTaxStrategy() = default;

     ~FlatTaxStrategy() = default;

    int calculateBuildingTax(int value) override;

    int calculateCitizenTax(int earnings) override;
};

#endif // FLATTAXSTRATEGY_H

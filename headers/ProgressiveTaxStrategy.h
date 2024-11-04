#ifndef PROGRESSIVETAXSTRATEGY_H
#define PROGRESSIVETAXSTRATEGY_H

#include "TaxStrategy.h"

class ProgressiveTaxStrategy : public TaxStrategy {

public:
    ProgressiveTaxStrategy() = default;
    ~ProgressiveTaxStrategy() = default;
    int calculateBuildingTax(int value) override;
    int calculateCitizenTax(int earnings) override;
};

#endif // PROGRESSIVETAXSTRATEGY_H

#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H


class TaxStrategy {
public:
    TaxStrategy() = default;
    virtual ~TaxStrategy() = default;

    virtual int calculateBuildingTax(int value) = 0;

    virtual int calculateCitizenTax(int earnings) = 0;
};

#endif // TAXSTRATEGY_H

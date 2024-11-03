#include "BudgetDepartment.h"

#include "FlatTaxStrategy.h"
#include "ProgressiveTaxStrategy.h"
#include "TaxAuthority.h"

BudgetDepartment::BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {
    this->totalAvailable = 20000;
}

int BudgetDepartment::checkTotal() {
    return totalAvailable;
}

void BudgetDepartment::receiveTaxes() {
    int taxesCollected = taxAuthority->collectTaxes();
    totalAvailable += taxesCollected;
}

std::unique_ptr<TaxStrategy> BudgetDepartment::recommendTaxStrategy() {
    if(isBroke()) {
        return std::make_unique<FlatTaxStrategy>();
    } else {
        return std::make_unique<ProgressiveTaxStrategy>();
    }
}

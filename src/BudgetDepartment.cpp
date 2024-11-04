#include "BudgetDepartment.h"
#include "TaxAuthority.h"

BudgetDepartment::BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {
    this->totalAvailable = 20000; // Initial budget
}

int BudgetDepartment::checkTotal() {
    return totalAvailable;
}

void BudgetDepartment::receiveTaxes() {
    int taxesCollected = taxAuthority->collectTaxes();
    totalAvailable += taxesCollected;
}

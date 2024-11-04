#include "BudgetDepartment.h"
#include "TaxAuthority.h"

BudgetDepartment::BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {
    this->totalAvailable = 20000; // Initial budget
}

int BudgetDepartment::checkTotal() {
    return totalAvailable;
}

int BudgetDepartment::receiveTaxes() {
    int taxesCollected = taxAuthority->collectTaxes();
    totalAvailable += taxesCollected;
    return taxesCollected;
}

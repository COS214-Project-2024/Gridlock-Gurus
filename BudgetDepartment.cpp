#include "BudgetDepartment.h"

BudgetDepartment::BudgetDepartment() : totalAvailable(0), broke(false) {}

int BudgetDepartment::checkTotal() {
    return totalAvailable;
}

bool BudgetDepartment::checkAvailability(int amount, TaxAuthority* taxAuthority) {
    if (totalAvailable < amount){
        receiveTaxes(taxAuthority);
    }
    return ;
}

void BudgetDepartment::gain(int amount) {
    totalAvailable += amount;
    if (totalAvailable > 0) {
        broke = false;
    }
}

void BudgetDepartment::lose(int amount) {
    if (amount <= totalAvailable) {
        totalAvailable -= amount;
    } else {
        totalAvailable = 0;
        broke = true;
    }
}

void BudgetDepartment::inflation(int percentage) {
    int reduction = (totalAvailable * percentage) / 100;
    lose(reduction);
}

void BudgetDepartment::receiveTaxes(TaxAuthority* taxAuthority) {
    int taxesCollected = taxAuthority->collectTaxes();
    gain(taxesCollected);
}

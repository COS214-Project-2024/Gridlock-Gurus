#include "BudgetDepartment.h"
#include "TaxAuthority.h"

BudgetDepartment::BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {
    this->totalAvailable = 0;
    this->broke = false;
}

int BudgetDepartment::checkTotal() {
    return totalAvailable;
}

bool BudgetDepartment::checkAvailability(int amount) {
    if (totalAvailable < amount){
        receiveTaxes();
        if (totalAvailable > amount){
            return true;
        }
        else return false;
    }
    else return false;
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

void BudgetDepartment::receiveTaxes() {
    int taxesCollected = taxAuthority->collectTaxes();
    gain(taxesCollected);
}

bool BudgetDepartment::isBroke() {
    return broke;
}

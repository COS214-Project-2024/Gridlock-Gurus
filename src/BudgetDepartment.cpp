/**
* @class BudgetDepartment
 * @brief Definition of the BudgetDepartment class, responsible for managing the city's budget.
 */

#include "BudgetDepartment.h"
#include "TaxAuthority.h"

/**
 * @brief Constructs a BudgetDepartment object.
 *
 * @param taxAuthority Shared pointer to the tax authority that collects taxes for the city.
 */
BudgetDepartment::BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {
    this->totalAvailable = 20000; // Initial budget
}

/**
 * @brief Checks the total available budget.
 *
 * @return An integer representing the total available budget.
 */
int BudgetDepartment::checkTotal() {
    return totalAvailable;
}

/**
 * @brief Receives taxes from the tax authority and updates the total budget.
 */
void BudgetDepartment::receiveTaxes() {
    int taxesCollected = taxAuthority->collectTaxes();
    totalAvailable += taxesCollected;
}

#ifndef BUDGETDEPARTMENT_H
#define BUDGETDEPARTMENT_H

class TaxStrategy;
class TaxAuthority;
#include <memory>


/**
 * @brief Manages the city's budget and financial allocations.
 *
 * The BudgetDepartment class is responsible for tracking the total available budget,
 * managing financial transactions, and handling adjustments such as inflation and tax relief.
 */
class BudgetDepartment {
private:
    int totalAvailable;  ///< The total available budget.
    std::shared_ptr<TaxAuthority> taxAuthority;

public:
    /**
     * @brief Constructs a new BudgetDepartment object.
     */
    BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority);

    /**
     * @brief Destroys the BudgetDepartment object.
     */
     ~BudgetDepartment() = default;

    /**
     * @brief Checks the total available budget.
     * @return The total available budget.
     */
    int checkTotal();

    void receiveTaxes();

    bool isBroke() {
        return totalAvailable <= 100;
    }

    std::unique_ptr<TaxStrategy> recommendTaxStrategy();
};

#endif // BUDGETDEPARTMENT_H

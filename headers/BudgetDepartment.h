#ifndef BUDGETDEPARTMENT_H
#define BUDGETDEPARTMENT_H

#include <memory>

/**
 * @brief Forward declaration of TaxAuthority.
 */
class TaxAuthority;

/**
 * @class BudgetDepartment
 * @brief Manages and allocates budget for various city functions.
 */
class BudgetDepartment {
private:
    int totalAvailable;  /**< Total budget available */
    std::shared_ptr<TaxAuthority> taxAuthority; /**< Pointer to the TaxAuthority for managing taxes */

public:
    /**
     * @brief Constructs a new BudgetDepartment object.
     * @param taxAuthority Shared pointer to the associated TaxAuthority.
     */
    BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority);

    /**
     * @brief Default destructor for the BudgetDepartment.
     */
    ~BudgetDepartment() = default;

    /**
     * @brief Checks the total budget available.
     * @return The total budget.
     */
    int checkTotal();

    /**
     * @brief Receives and adds collected taxes to the budget.
     */
    int receiveTaxes();

    /**
     * @brief Checks if the budget department is broke.
     * @return true if total available is less than or equal to 0, false otherwise.
     */
    bool isBroke() {
        return totalAvailable <= 0;
    }
};

#endif // BUDGETDEPARTMENT_H

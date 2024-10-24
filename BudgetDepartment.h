#ifndef BUDGETDEPARTMENT_H
#define BUDGETDEPARTMENT_H

/**
 * @brief Manages the city's budget and financial allocations.
 *
 * The BudgetDepartment class is responsible for tracking the total available budget,
 * managing financial transactions, and handling adjustments such as inflation and tax relief.
 */
class BudgetDepartment {
private:
    int totalAvailable;  ///< The total available budget.
    bool broke;  ///< Indicates whether the budget department is out of funds.

public:
    /**
     * @brief Constructs a new BudgetDepartment object.
     */
    BudgetDepartment();

    /**
     * @brief Destroys the BudgetDepartment object.
     */
    virtual ~BudgetDepartment();

    /**
     * @brief Checks the total available budget.
     * @return The total available budget.
     */
    int checkTotal();

    /**
     * @brief Checks if the specified amount is available in the budget.
     * @param amount The amount to check for availability.
     * @return True if the amount is available, false otherwise.
     */
    bool checkAvailability(int amount);

    /**
     * @brief Increases the total available budget by the specified amount.
     * @param amount The amount to add to the total budget.
     */
    void gain(int amount);

    /**
     * @brief Decreases the total available budget by the specified amount.
     * @param amount The amount to subtract from the total budget.
     */
    void lose(int amount);

    /**
     * @brief Adjusts the total budget based on an inflation percentage.
     * @param percentage The percentage by which to increase the budget due to inflation.
     */
    void inflation(int percentage);

    /**
     * @brief Applies tax relief by reducing the budget based on a percentage.
     * @param percentage The percentage of tax relief to apply.
     */
    void taxRelief(int percentage);
};

#endif // BUDGETDEPARTMENT_H

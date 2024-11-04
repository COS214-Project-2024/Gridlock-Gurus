#include "Government.h"

std::shared_ptr<Government> Government::instance = nullptr;

/**
 * @brief Retrieves the singleton instance of the Government class.
 *
 * This method ensures that only one instance of the Government class
 * exists throughout the application and provides access to that instance.
 *
 * @return A shared pointer to the Government instance.
 */
std::shared_ptr<Government> Government::getInstance() {
    if (instance == nullptr) {
        instance = std::shared_ptr<Government>(new Government());
    }
    return instance;}

/**
 * @brief Constructs a Government object.
 *
 * Initializes the government by creating instances of various departments
 * such as TaxAuthority, TransportDepartment, BudgetDepartment, and others.
 */
Government::Government() {
        taxAuthority = std::make_shared<TaxAuthority>();
        transportDepartment = std::make_shared<TransportDepartment>();
        budgetDepartment = std::make_shared<BudgetDepartment>(taxAuthority);
        utilities = std::make_shared<DepartmentOfWaterPowerAndSanitation>();
        homeAffairs = std::make_shared<DepartmentOfHomeAffairs>(taxAuthority);
}


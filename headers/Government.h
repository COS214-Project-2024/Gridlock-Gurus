#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "TaxAuthority.h"
#include "TransportDepartment.h"
#include "BudgetDepartment.h"
#include "DepartmentOfWaterPowerAndSanitation.h"
#include "DepartmentOfHomeAffairs.h"
#include <memory>

/**
 * @class Government
 * @brief Singleton class representing the government.
 * 
 * This class manages various departments such as Tax Authority, Transport Department, 
 * Budget Department, Department of Water, Power and Sanitation, and Home Affairs. 
 * It ensures that only one instance of Government exists.
 */
class Government {
private:
    static std::shared_ptr<Government> instance;                    ///< The singleton instance of Government
    std::shared_ptr<TaxAuthority> taxAuthority;                     ///< Tax authority managed by the government
    std::shared_ptr<TransportDepartment> transportDepartment;       ///< Transport department managed by the government
    std::shared_ptr<BudgetDepartment> budgetDepartment;             ///< Budget department managed by the government
    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> utilities; ///< Utility department managed by the government
    std::shared_ptr<DepartmentOfHomeAffairs> homeAffairs;           ///< Home affairs department managed by the government

    // Delete copy constructor and assignment operator
    // Government(const Government&) = delete;
    // Government& operator=(const Government&) = delete;

    /** 
     * @brief Private constructor for singleton pattern.
     */
    Government();

public:
    /**
     * @brief Get the instance of the Government class.
     * @return A shared pointer to the Government instance.
     */
    static std::shared_ptr<Government> getInstance();

    /** 
     * @brief Default destructor for Government class.
     */
    ~Government() = default;

    /**
     * @brief Get the Department of Water, Power and Sanitation.
     * @return A shared pointer to the utilities department.
     */
    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> getDepartmentOfWaterPowerAndSanitation() const {
        return utilities;
    }

    /**
     * @brief Get the Tax Authority.
     * @return A shared pointer to the TaxAuthority.
     */
    std::shared_ptr<TaxAuthority> getTaxAuthority() const {
        return taxAuthority;
    }

    /**
     * @brief Get the Department of Home Affairs.
     * @return A shared pointer to the home affairs department.
     */
    std::shared_ptr<DepartmentOfHomeAffairs> getDepartmentOfHomeAffairs() const {
        return homeAffairs;
    }

    /**
     * @brief Get the Transport Department.
     * @return A shared pointer to the TransportDepartment.
     */
    std::shared_ptr<TransportDepartment> getTransportDepartment() const {
        return transportDepartment;
    }

    /**
     * @brief Get the Budget Department.
     * @return A shared pointer to the BudgetDepartment.
     */
    std::shared_ptr<BudgetDepartment> getBudgetDepartment() const {
        return budgetDepartment;
    }

};

#endif // GOVERNMENT_H



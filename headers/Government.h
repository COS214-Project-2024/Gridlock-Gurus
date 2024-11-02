#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "TaxAuthority.h"
#include "TransportDepartment.h"
#include "BudgetDepartment.h"
#include "DepartmentOfWaterPowerAndSanitation.h"
#include "DepartmentOfHomeAffairs.h"
#include <memory>

/**
 * @brief Manages the city's government system and departments.
 *
 * The Government class coordinates various city departments, including tax authority,
 * transport, budget, utilities, and home affairs, ensuring their operations align with
 * the city's governance objectives.
 */
class Government {
private:
    static std::shared_ptr<Government> instance;
    std::shared_ptr<TaxAuthority> taxAuthority;                 ///< Pointer to the TaxAuthority managing taxation.
    std::shared_ptr<TransportDepartment> transportDepartment;    ///< Pointer to the TransportDepartment managing transport services.
    std::shared_ptr<BudgetDepartment> budgetDepartment;          ///< Pointer to the BudgetDepartment handling city finances.
    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> utilities;  ///< Pointer to the Department of Water and Sanitation managing utilities.
    std::shared_ptr<DepartmentOfHomeAffairs> homeAffairs;       ///< Pointer to the Department of Home Affairs managing citizen registrations.

    // Delete copy constructor and assignment operator
    Government(const Government&) = delete;
    Government& operator=(const Government&) = delete;
    Government();

public:
   /**
     * @brief Get the singleton instance of Government.
     * 
     * @return std::shared_ptr<Government> The singleton instance.
     */
    static std::shared_ptr<Government> getInstance();

    /**
     * @brief Destroy the Government object.
     *
     * Cleans up resources and deletes pointers to all department objects.
     */
     ~Government() = default;

    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> getDepartmentOfWaterPowerAndSanitation() const {
        return utilities;
    }

    std::shared_ptr<TaxAuthority> getTaxAuthority() const {
        return taxAuthority;
    }

    std::shared_ptr<DepartmentOfHomeAffairs> getDepartmentOfHomeAffairs() const {
        return homeAffairs;
    }

     std::shared_ptr<TransportDepartment> getTransportDepartment() const {
        return transportDepartment;
    }

    std::shared_ptr<BudgetDepartment> getBudgetDepartment() const {
        return budgetDepartment;
    }


};

#endif // GOVERNMENT_H



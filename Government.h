#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "TaxAuthority.h"
#include "TransportDepartment.h"
#include "BudgetDepartment.h"
#include "DepartmentOfWaterPowerAndSanitation.h"
#include "DepartmentOfHomeAffairs.h"

/**
 * @brief Manages the city's government system and departments.
 *
 * The Government class coordinates various city departments, including tax authority,
 * transport, budget, utilities, and home affairs, ensuring their operations align with
 * the city's governance objectives.
 */
class Government {
private:
    TaxAuthority* taxAuthority;                 ///< Pointer to the TaxAuthority managing taxation.
    TransportDepartment* transportDepartment;    ///< Pointer to the TransportDepartment managing transport services.
    BudgetDepartment* budgetDepartment;          ///< Pointer to the BudgetDepartment handling city finances.
    DepartmentOfWaterPowerAndSanitation* utilities;  ///< Pointer to the Department of Water and Sanitation managing utilities.
    DepartmentOfHomeAffairs* homeAffairs;       ///< Pointer to the Department of Home Affairs managing citizen registrations.

public:
    /**
     * @brief Construct a new Government object.
     *
     * Initializes the Government and sets up pointers to all relevant departments.
     */
    Government();

    /**
     * @brief Destroy the Government object.
     *
     * Cleans up resources and deletes pointers to all department objects.
     */
    virtual ~Government();
virtual corrupt();
};

#endif // GOVERNMENT_H



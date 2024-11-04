#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "TaxAuthority.h"
#include "TransportDepartment.h"
#include "BudgetDepartment.h"
#include "DepartmentOfWaterPowerAndSanitation.h"
#include "DepartmentOfHomeAffairs.h"
#include <memory>

class Government {
private:
    static std::shared_ptr<Government> instance;
    std::shared_ptr<TaxAuthority> taxAuthority;
    std::shared_ptr<TransportDepartment> transportDepartment;
    std::shared_ptr<BudgetDepartment> budgetDepartment;
    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> utilities;
    std::shared_ptr<DepartmentOfHomeAffairs> homeAffairs;

    // Delete copy constructor and assignment operator
    Government(const Government&) = delete;
    Government& operator=(const Government&) = delete;
    Government();

public:
    static std::shared_ptr<Government> getInstance();

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



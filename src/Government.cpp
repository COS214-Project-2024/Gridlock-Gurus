#include "Government.h"

std::shared_ptr<Government> Government::instance = nullptr;

std::shared_ptr<Government> Government::getInstance() {
    if (instance == nullptr) {
        instance = std::shared_ptr<Government>(new Government());
    }
    return instance;
}

Government::Government() {
        taxAuthority = std::make_shared<TaxAuthority>();
        transportDepartment = std::make_shared<TransportDepartment>();
        budgetDepartment = std::make_shared<BudgetDepartment>(taxAuthority);
        utilities = std::make_shared<DepartmentOfWaterPowerAndSanitation>();
        homeAffairs = std::make_shared<DepartmentOfHomeAffairs>(taxAuthority);
}


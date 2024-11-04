#ifndef BUDGETDEPARTMENT_H
#define BUDGETDEPARTMENT_H

class TaxAuthority;
#include <memory>

class BudgetDepartment {
private:
    int totalAvailable;
    std::shared_ptr<TaxAuthority> taxAuthority;

public:
    BudgetDepartment(std::shared_ptr<TaxAuthority> taxAuthority);
     ~BudgetDepartment() = default;
    int checkTotal();
    void receiveTaxes();
    bool isBroke() {
        return totalAvailable <= 0;
    }
};

#endif // BUDGETDEPARTMENT_H

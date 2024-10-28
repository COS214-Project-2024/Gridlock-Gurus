#include "Government.h"

Government* Government::getInstance() {
    static Government instance;
    return &instance;
}

Government::Government() : taxAuthority(new TaxAuthority()),
    transportDepartment(new TransportDepartment()),
    budgetDepartment(new BudgetDepartment()),
    utilities(new DepartmentOfWaterPowerAndSanitation()),
    homeAffairs(new DepartmentOfHomeAffairs()) {}

Government::~Government() {
    delete taxAuthority;
    delete transportDepartment;
    delete budgetDepartment;
    delete utilities;
    delete homeAffairs;
}

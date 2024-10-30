#include "Government.h"

Government* Government::getInstance() {
    static Government instance;
    return &instance;
}

Government::Government() : taxAuthority(std::make_shared<TaxAuthority>()),
    transportDepartment(new TransportDepartment()),
    budgetDepartment(new BudgetDepartment()),
    utilities(new DepartmentOfWaterPowerAndSanitation(new Resources(5000, 5000, true))),
    homeAffairs(new DepartmentOfHomeAffairs()) {}

Government::~Government() {
    //delete taxAuthority;
    delete transportDepartment;
    delete budgetDepartment;
    delete utilities;
    delete homeAffairs;
}

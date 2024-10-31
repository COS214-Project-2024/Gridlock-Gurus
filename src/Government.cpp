#include "Government.h"

Government* Government::getInstance() {
    static Government instance;
    return &instance;
}

Government::Government()  {
    this->taxAuthority = std::make_shared<TaxAuthority>();
    this->budgetDepartment = new BudgetDepartment(taxAuthority);
    this->utilities = new DepartmentOfWaterPowerAndSanitation(new Resources(5000, 5000, true));
    this->homeAffairs = new DepartmentOfHomeAffairs(taxAuthority);
    this->transportDepartment = new TransportDepartment();
}

Government::~Government() {
    delete transportDepartment;
    delete budgetDepartment;
    delete utilities;
    delete homeAffairs;
}

#include "Government.h"

Government* Government::getInstance() {
    static Government instance;
    return &instance;
}

Government::Government()  {
    this->taxAuthority = new TaxAuthority();
    this->budgetDepartment = new BudgetDepartment(taxAuthority);
    this->utilities = new DepartmentOfWaterPowerAndSanitation(new Resources(5000, 5000, true));
    this->homeAffairs = new DepartmentOfHomeAffairs();
    this->transportDepartment = new TransportDepartment()
}

Government::~Government() {
    delete taxAuthority;
    delete transportDepartment;
    delete budgetDepartment;
    delete utilities;
    delete homeAffairs;
}

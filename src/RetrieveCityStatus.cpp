#include "RetrieveCityStatus.h"

void RetrieveCityStatus::execute(){
  int citizenCount = city->getCitizenCount();
  int employmentCount = city->getWorkierCount();
  int unemployment = ((citizenCount - employmentCount)/citizenCount)*100;
  std::cout << "City Status:" << std::endl;
  std::cout << "Citizen happiness levels: \t" << city->getCitizenHappiness() << std::endl;
  std::cout << "City state: \t" << city->getState() << std::endl;
  std::cout << "Population: \t" << city->getCitizenCount() << std::endl;
  std::cout << "Unemployment rate: \t" << unemployment << "%" << std::endl;
  status = EXECUTED;
}

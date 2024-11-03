#include "ChangeTaxStrategyCommand.h"

void ChangeTaxStrategyCommand::execute(){
  city->changeTaxStrategy();
  std::cout<< "Changed tax strategy" << std::endl;
}
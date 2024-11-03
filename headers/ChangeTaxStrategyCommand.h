#ifndef CHANGETAXSTRATEGYCOMMAND_H
#define CHANGETAXSTRATEGYCOMMAND_H

#include "Command.h"
#include "City.h"

class ChangeTaxStrategyCommand : public Command{
    City*& city;
public:
  ChangeTaxStrategyCommand(City*& city) : city(city){};
  ~ChangeTaxStrategyCommand(){};
  void execute() override;
};



#endif //CHANGETAXSTRATEGYCOMMAND_H

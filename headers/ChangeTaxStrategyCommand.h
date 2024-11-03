#ifndef CHANGETAXSTRATEGYCOMMAND_H
#define CHANGETAXSTRATEGYCOMMAND_H

#include "Command.h"
#include "City.h"

class ChangeTaxStrategyCommand : public Command{
public:
  ChangeTaxStrategyCommand();
  ~ChangeTaxStrategyCommand(){};
  void execute() override;
};



#endif //CHANGETAXSTRATEGYCOMMAND_H

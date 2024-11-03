#ifndef RESETCOMMAND_H
#define RESETCOMMAND_H

#include "Command.h"
#include "City.h"
#include "Director.h"

class ResetCommand : public Command{
    City*& city;
    Director& director;
public:
  ResetCommand(City*& city, Director& director) : city(city), director(director){};
  void execute() override;
  //possibly find a way to undo but that's a lot - it'll need a new momento
};



#endif //RESETCOMMAND_H

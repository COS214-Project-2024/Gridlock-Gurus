#ifndef RETRIEVECITYSTATUS_H
#define RETRIEVECITYSTATUS_H

#include "City.h"
#include "Command.h"

class RetrieveCityStatus : public Command {
    City*& city;
public:
  RetrieveCityStatus(City*& city) : city(city) {};
  ~RetrieveCityStatus() {};
  void execute() override;
};



#endif //RETRIEVECITYSTATUS_H

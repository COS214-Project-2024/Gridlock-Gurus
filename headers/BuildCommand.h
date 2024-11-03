#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"
#include "City.h"
#include "Director.h"
#include "BuildingType.h"
#include "Citizen.h"
#include <iostream>

class Director;
class Building;
class Citizen;
class City;
class BuildCommand : public Command {
    City& city;
    Director& director;
    BuildingType buildingType;
public:
    BuildCommand(City& city, Director& director, BuildingType buildingType) : city(city), director(director), buildingType(buildingType){}
    ~BuildCommand() override = default;
    void execute() override;
    void undo() override ;
    void redo() override;

};
#endif // BUILDCOMMAND_H

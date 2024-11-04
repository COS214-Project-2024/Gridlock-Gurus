#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"
#include "City.h"
#include "BuildingType.h"
#include "Citizen.h"
#include <iostream>
#include <memory>

class Building;
class City;
class BuildCommand : public Command {
    BuildingType type;

public:
    
    BuildCommand(std::shared_ptr<City> city, BuildingType type) : Command (city){
        this->type = type;
    }

    
    ~BuildCommand() override = default;
    void execute() override;

};
#endif // BUILDCOMMAND_H

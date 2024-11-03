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
/**
 * @brief Command to handle the construction of buildings in the city.
 *
 * ConcreteCommand participant in the Command design pattern. It implements the `execute()` method to handle building construction.
 */
class BuildCommand : public Command {
    BuildingType type;

public:
    /**
     * @brief Constructs a new BuildCommand object.
     */
    BuildCommand(std::shared_ptr<City> city, BuildingType type) : Command (city){
        this->type = type;
    }

    /**
     * @brief Destroys the BuildCommand object.
     */
    ~BuildCommand() override = default;

    /**
     * @brief Executes the command to construct a building.
     */
    void execute() override;


};
#endif // BUILDCOMMAND_H

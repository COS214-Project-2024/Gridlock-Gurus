#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"
#include "City.h"
#include "Director.h"
#include "BuildingFactory.h"
#include "BuildingType.h"
#include "Citizen.h"
#include <iostream>

class Director;
class BuildingFactory;
class Building;
class Citizen;
class City;
/**
 * @brief Command to handle the construction of buildings in the city.
 *
 * ConcreteCommand participant in the Command design pattern. It implements the `execute()` method to handle building construction.
 */
class BuildCommand : public Command {
    City& city;
    Director& director;
    BuildingFactory& buildingFactory;
    BuildingType buildingType;
    Building* constructedBuilding;
    Citizen& citizen;
public:
    /**
     * @brief Constructs a new BuildCommand object.
     */
    BuildCommand(City& city, Director& director, BuildingFactory& factory, BuildingType buildingType,Citizen& citizen) : city(city), director(director), buildingFactory(factory), buildingType(buildingType), citizen(citizen) {}


    /**
     * @brief Destroys the BuildCommand object.
     */
    ~BuildCommand() override = default;

    /**
     * @brief Executes the command to construct a building.
     */
    void execute() override;

    /**
     * @brief Undo functionality.
     */
    void undo() override ;

    /**
     * @brief Redo functionality.
     */
    void redo() override;

};
#endif // BUILDCOMMAND_H

#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"
#include "City.h"
#include "BuildingType.h"
#include "Citizen.h"
#include <iostream>
#include <memory>

/**
 * @brief Forward declaration of Building and City class.
 */
class Building;
class City;

/**
 * @class BuildCommand
 * @brief Command for building a specific building type in a city.
 */
class BuildCommand : public Command {
    BuildingType type; /**< Type of building to construct */

public:
    /**
     * @brief Constructs a BuildCommand object.
     * @param city Shared pointer to the city where the building will be constructed.
     * @param type Type of the building to be constructed.
     */
    BuildCommand(std::shared_ptr<City> city, BuildingType type) : Command(city) {
        this->type = type;
    }

    /**
     * @brief Default destructor for BuildCommand.
     */
    ~BuildCommand() override = default;

    /**
     * @brief Executes the build command, creating the specified building in the city.
     */
    void execute() override;
};

#endif // BUILDCOMMAND_H

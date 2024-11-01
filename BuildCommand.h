#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"

/**
 * @brief Command to handle the construction of buildings in the city.
 *
 * ConcreteCommand participant in the Command design pattern. It implements the `execute()` method to handle building construction.
 */
class BuildCommand : public Command {
public:
    /**
     * @brief Constructs a new BuildCommand object.
     */
    BuildCommand();

    /**
     * @brief Destroys the BuildCommand object.
     */
    virtual ~BuildCommand();

    /**
     * @brief Executes the command to construct a building.
     */
    void execute() override;

     /**
     * @brief Undo functionality.
     */
    void undo();
};

#endif // BUILDCOMMAND_H

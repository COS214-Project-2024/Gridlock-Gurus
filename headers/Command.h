#ifndef COMMAND_H
#define COMMAND_H

#include "City.h"
#include <memory>

/**
 * @brief Abstract base class for commands that can be executed on a city.
 */
class Command {
protected:
    std::shared_ptr<City> city; ///< Pointer to the city on which the command will be executed.

public:
    /**
     * @brief Constructs a Command object with the specified city.
     * @param city Pointer to the city.
     */
    Command(std::shared_ptr<City> city) : city(city) {}

    /**
     * @brief Default virtual destructor.
     */
    virtual ~Command() = default;

    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;
};

#endif // COMMAND_H

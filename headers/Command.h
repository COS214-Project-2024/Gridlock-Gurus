#ifndef COMMAND_H
#define COMMAND_H
#include <memory>

#include "City.h"

/**
 * @brief Enum for command status.
 */
 enum Status {
    PENDING,
    EXECUTED,
    UNDONE
 };

/**
 * @brief Abstract class representing a command in the simulation.
 *
 * Command participant in the Command design pattern. It declares the `execute()` method that all concrete commands must implement.
 */
class Command {
protected:
    std::shared_ptr<City> city;
    Status status;
    int executionCount;
public:
    /**
     * @brief Constructs a new Command object.
     */
    Command();

    /**
     * @brief Destroys the Command object.
     */
    virtual ~Command() = default;

    /**
     * @brief Executes the command.
     *
     * This is a pure virtual function that concrete command classes must implement.
     */
    virtual void execute() = 0;
      /**
     * @brief Check if executed.
     */
    void executed();

     /**
     * @brief Optionally undoes the command.
     */
    virtual void undo();

    /**
     * @brief Optionally re-executes the command after an undo.
     */
    virtual void redo();

    /**
     * @brief Gets the status of the command.
     * @return The current status of the command (PENDING, EXECUTED, or UNDONE).
     */
    Status getStatus() const;

    /**
     * @brief Gets the execution count of the command.
     * @return The number of times the command has been executed.
     */
    int getExecutionCount() const;

};

#endif // COMMAND_H

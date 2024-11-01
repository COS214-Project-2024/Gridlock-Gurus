#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief Abstract class representing a command in the simulation.
 *
 * Command participant in the Command design pattern. It declares the `execute()` method that all concrete commands must implement.
 */
class Command {
public:
    /**
     * @brief Constructs a new Command object.
     */
    Command();

    /**
     * @brief Destroys the Command object.
     */
    virtual ~Command();

    
    /**
     * @brief Enum for command status.
     */
    enum Status {
        PENDING,
        EXECUTED,
        UNDONE
    };

    /**
     * @brief Executes the command.
     *
     * This is a pure virtual function that concrete command classes must implement.
     */
    virtual void execute() = 0;

    private:
        Status status;
        int executionCount;
        
};

#endif // COMMAND_H

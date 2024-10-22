#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief Abstract class representing a command in the simulation.
 */
class Command {
public:
    Command();  ///< Constructor
    virtual ~Command();  ///< Destructor
};

#endif // COMMAND_H


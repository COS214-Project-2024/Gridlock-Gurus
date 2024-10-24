#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include "Command.h"

/**
 * @brief Command to handle the taxation system in the city.
 *
 * ConcreteCommand participant in the Command design pattern. It implements the `execute()` method to handle tax-related operations.
 */
class TaxCommand : public Command {
public:
    /**
     * @brief Constructs a new TaxCommand object.
     */
    TaxCommand();

    /**
     * @brief Destroys the TaxCommand object.
     */
    ~TaxCommand();

    /**
     * @brief Executes the command to manage taxes.
     */
    void execute() override;
};

#endif // TAXCOMMAND_H
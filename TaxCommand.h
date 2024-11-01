#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include "Command.h"

/**
 * @brief Command to handle the taxation system in the city.
 *
 * ConcreteCommand participant in the Command design pattern. It implements the `execute()` method to handle tax-related operations.
 */
class TaxCommand : public Command {
private:
    TaxAuthority* taxAuthority;
    int taxRate;
    int previousTaxRate; // Store previous tax rate for undo/redo

public:
    /**
     * @brief Constructs a new TaxCommand object.
     */
    TaxCommand();

    /**
     * @brief Destroys the TaxCommand object.
     */
    virtual ~TaxCommand();

    /**
     * @brief Executes the command to manage taxes.
     */
    void execute() override;

    /**
     * @brief Undo functionality.
     */
    void undo() override;

    /**
     * @brief Redo functionality.
     */
    void redo() override;
};

#endif // TAXCOMMAND_H

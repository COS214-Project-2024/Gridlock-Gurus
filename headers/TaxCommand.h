#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include "Command.h"
#include "TaxAuthority.h"
#include "TaxStrategy.h"
#include <memory>

/**
 * @brief Command to handle the taxation system in the city.
 *
 * ConcreteCommand participant in the Command design pattern. It implements the `execute()` method to handle tax-related operations.
 */
class TaxCommand : public Command {
    std::shared_ptr<TaxAuthority> taxAuthority;
    std::unique_ptr<TaxStrategy> taxStrategy;

public:
    /**
     * @brief Constructs a new TaxCommand object.
     * @param taxAuth Shared pointer to TaxAuthority.
     * @param taxStrat Unique pointer to TaxStrategy, transferred with std::move.
     */
  TaxCommand(std::shared_ptr<TaxAuthority> taxAuth, std::unique_ptr<TaxStrategy> taxStrat)
        : taxAuthority(taxAuth), taxStrategy(std::move(taxStrat)) {}
    /**
     * @brief Destroys the TaxCommand object.
     */
    ~TaxCommand()override = default;

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

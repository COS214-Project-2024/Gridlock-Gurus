#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include "Command.h"
#include "TaxAuthority.h"
#include "TaxStrategy.h"
#include <memory>


class TaxCommand : public Command {
    std::shared_ptr<TaxAuthority> taxAuthority;
    std::unique_ptr<TaxStrategy> taxStrategy;

public:
  TaxCommand(std::shared_ptr<TaxAuthority> taxAuth, std::unique_ptr<TaxStrategy> taxStrat)
        : taxAuthority(taxAuth), taxStrategy(std::move(taxStrat)) {}
    ~TaxCommand()override = default;

    void execute() override;

    void undo() override;

    void redo() override;
};

#endif // TAXCOMMAND_H

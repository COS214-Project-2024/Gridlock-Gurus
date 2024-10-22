#ifndef TAXCOMMAND_H
#define TAXCOMMAND_H

#include "Command.h"

/**
 * @brief Command to handle the taxation system in the city.
 */
class TaxCommand : public Command {
public:
    TaxCommand();  ///< Constructor
    ~TaxCommand();  ///< Destructor
};

#endif // TAXCOMMAND_H

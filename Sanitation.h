#ifndef SANITATION_H
#define SANITATION_H

#include "Utilities.h"
#include "UtilityType.h"

/**
 * @brief Represents a Sanitation utility.
 */
class Sanitation : public Utilities {
public:
    /**
     * @brief Constructor for Sanitation utility.
     */
    Sanitation() : Utilities(UtilityType::Sanitation,300,300) {}

    ~Sanitation()override = default;

    /**
     * @brief Check the sanitation capacity.
     * @return The current sanitation capacity.
     */
    void checkCapacity() const override;

    void shed() override;
    void breakUtility() override;
    void repair() override;
};

#endif // SANITATION_H

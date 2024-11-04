#ifndef SANITATION_H
#define SANITATION_H

#include "Utilities.h"
#include "UtilityType.h"

/**
 * @class Sanitation
 * @brief Represents the sanitation utility service.
 */
class Sanitation : public Utilities {
public:
    /**
     * @brief Constructs a new Sanitation utility.
     */
    Sanitation() : Utilities(UtilityType::Sanitation, 300, 300) {}

    /**
     * @brief Destroys the Sanitation utility.
     */
    ~Sanitation() override = default;

    /**
     * @brief Checks the capacity of the sanitation utility.
     */
    void checkCapacity() const override;

    /**
     * @brief Sheds the load of the sanitation utility.
     */
    void shed() override;

    /**
     * @brief Breaks the sanitation utility.
     */
    void breakUtility() override;

    /**
     * @brief Repairs the sanitation utility.
     */
    void repair() override;
};

#endif // SANITATION_H
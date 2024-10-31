#ifndef SANITATION_H
#define SANITATION_H

#include "Utilities.h"

/**
 * @brief Represents a Sanitation utility.
 */
class Sanitation : public Utilities {
public:
    /**
     * @brief Constructor for Sanitation utility.
     */
    Sanitation();

    virtual ~Sanitation();

    /**
     * @brief Check the sanitation capacity.
     * @return The current sanitation capacity.
     */
    void checkCapacity() const override;

    // /**
    //  * @brief Shed sanitation temporarily.
    //  */
    // void shed() override;

    // /**
    //  * @brief Break the sanitation utility.
    //  */
    // void breakUtility() override;

    // /**
    //  * @brief Repair the sanitation utility.
    //  */
    // void repair() override;
};

#endif // SANITATION_H

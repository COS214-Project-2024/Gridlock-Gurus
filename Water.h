#ifndef WATER_H
#define WATER_H

#include "Utilities.h"

/**
 * @brief Represents a Water utility.
 */
class Water : public Utilities {
public:
    /**
     * @brief Constructor for Water utility.
     */
    Water();

    ~Water();

    /**
     * @brief Check the water capacity.
     * @return The current water capacity.
     */
    int checkCapacity() const override;

    /**
     * @brief Shed water temporarily.
     */
    void shed() override;

    /**
     * @brief Break the water utility.
     */
    void breakUtility() override;

    /**
     * @brief Repair the water utility.
     */
    void repair() override;
};

#endif // WATER_H

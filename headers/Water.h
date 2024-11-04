#ifndef WATER_H
#define WATER_H

#include "Utilities.h"
#include "UtilityType.h"

/**
 * @class Water
 * @brief Represents a water utility in the system.
 */

class Water : public Utilities {
public:
    /**
     * @brief Constructs a new Water object with default values.
     */
    Water() : Utilities(UtilityType::Water, 500, 300) {}

    /**
     * @brief Destroys the Water object.
     */
    ~Water() override = default;

    /**
     * @brief Checks the capacity of the water utility.
     */
    void checkCapacity() const override;

    /**
     * @brief Initiates reduction of water flow to conserve resources.
     */
    void shed() override;

    /**
     * @brief Simulates a breakdown of the water utility.
     */
    void breakUtility() override;

    /**
     * @brief Repairs the water utility.
     */
    void repair() override;
};

#endif // WATER_H

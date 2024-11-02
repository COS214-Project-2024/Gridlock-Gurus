#ifndef WATER_H
#define WATER_H

#include "Utilities.h"
#include "UtilityType.h"

/**
 * @brief Represents a Water utility.
 */
class Water : public Utilities {
public:
    /**
     * @brief Constructor for Water utility.
     */
    Water() : Utilities(UtilityType::Water, 500, 300) {}

     ~Water()override = default;

    /**
     * @brief Check the water capacity.
     * @return The current water capacity.
     */
    void checkCapacity() const override;

    void shed() override;
    void breakUtility() override;
    void repair() override;


};

#endif // WATER_H

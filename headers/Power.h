#ifndef POWER_H
#define POWER_H

#include "Utilities.h"
#include <string>
#include "UtilityType.h"
/**
 * @brief Represents a Power utility.
 */
class Power : public Utilities {
public:
    /**
     * @brief Constructor for Power utility.
     */
    Power() : Utilities(UtilityType::Power, 1000, 500) {}

    ~Power()override = default;

    /**
     * @brief Check the power capacity.
     * @return The current power capacity.
     */
    void checkCapacity() const override;

    // /**
    //  * @brief Shed power temporarily.
    //  */
    // void shed() override;

    // /**
    //  * @brief Break the power utility.
    //  */
    // void breakUtility() override;

    // /**
    //  * @brief Repair the power utility.
    //  */
    // void repair() override;
};

#endif // POWER_H

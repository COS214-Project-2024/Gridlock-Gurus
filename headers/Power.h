#ifndef POWER_H
#define POWER_H

#include "Utilities.h"
#include <string>
#include "UtilityType.h"

/**
 * @class Power
 * @brief Represents a power utility in the simulation.
 */
class Power : public Utilities {
public:
    /**
     * @brief Constructs a Power utility with default parameters.
     */
    Power() : Utilities(UtilityType::Power, 1000, 500) {}

    /**
     * @brief Destructor for Power utility.
     */
    ~Power() override = default;

    /**
     * @brief Checks the current capacity of the power utility.
     */
    void checkCapacity() const override;

    /**
     * @brief Sheds load to manage power distribution.
     */
    void shed() override;

    /**
     * @brief Simulates a breakdown of the power utility.
     */
    void breakUtility() override;

    /**
     * @brief Repairs the power utility after a breakdown.
     */
    void repair() override;
};

#endif // POWER_H

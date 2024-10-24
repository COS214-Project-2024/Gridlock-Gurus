#ifndef POWER_H
#define POWER_H

#include "Utilities.h"

/**
 * @brief Represents a Power utility.
 */
class Power : public Utilities {
public:
    /**
     * @brief Constructor for Power utility.
     */
    Power();

    virtual ~Power();

    /**
     * @brief Check the power capacity.
     * @return The current power capacity.
     */
    int checkCapacity() const override;

    /**
     * @brief Shed power temporarily.
     */
    void shed() override;

    /**
     * @brief Break the power utility.
     */
    void breakUtility() override;

    /**
     * @brief Repair the power utility.
     */
    void repair() override;
};

#endif // POWER_H

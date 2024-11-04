#ifndef UTILITIES_H
#define UTILITIES_H

#include "UtilityType.h"
#include <string>

/**
 * @class Utilities
 * @brief Base class for different utility types.
 */
class Utilities {
protected:
    UtilityType type; ///< Type of utility (e.g., Water, Power).
    int maxProduction; ///< Maximum production capacity.
    bool shedding; ///< Indicates if the utility is shedding load.
    bool isRepair; ///< Indicates if the utility is under repair.
    int costOfRepair; ///< Cost associated with repairing the utility.

public:
    /**
     * @brief Constructs a new Utilities object.
     * 
     * @param type The type of utility.
     * @param maxProduction The maximum production capacity.
     * @param costOfRepair The cost of repairing the utility.
     */
    Utilities(UtilityType type, int maxProduction, int costOfRepair);

    /**
     * @brief Checks the current production capacity of the utility.
     */
    virtual void checkCapacity() const;

    /**
     * @brief Initiates load shedding for the utility.
     */
    virtual void shed();

    /**
     * @brief Simulates a breakdown of the utility.
     */
    virtual void breakUtility();

    /**
     * @brief Repairs the utility.
     */
    virtual void repair();

    /**
     * @brief Destroys the Utilities object.
     */
    virtual ~Utilities() = default;

    /**
     * @brief Gets the type of the utility.
     * @return The type of the utility.
     */
    UtilityType getType() const { 
        return type; 
    }

    /**
     * @brief Checks if the utility is shedding load.
     * @return true if shedding load, false otherwise.
     */
    bool isShedding() const { 
        return shedding; 
    }

    /**
     * @brief Checks if the utility is under repair.
     * @return true if under repair, false otherwise.
     */
    bool isBroken() const { 
        return isRepair; 
    }

    /**
     * @brief Gets the maximum production capacity of the utility.
     * @return The maximum production capacity.
     */
    int getMax() const {
        return maxProduction;
     }

    /**
     * @brief Gets the cost of repairing the utility.
     * @return The cost of repair.
     */
    int getCost() const {
        return costOfRepair;
    }

    /**
     * @brief Doubles the production capacity of the utility.
     */
    void upgradeProduction() {
        this->maxProduction *= 2;
    }
};

#endif // UTILITIES_H
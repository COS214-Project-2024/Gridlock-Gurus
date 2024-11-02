#ifndef UTILITIES_H
#define UTILITIES_H
#include "UtilityType.h"
#include <string>

/**
 * @brief Abstract class representing a utility.
 */
class Utilities {
protected:
    UtilityType type;
    int maxProduction;
    bool shedding;
    bool isRepair;
    int costOfRepair;

public:
    /**
     * @brief Default constructor for Utilities.
     */
    Utilities(UtilityType type, int maxProduction, int costOfRepair) : type(type), maxProduction(maxProduction),shedding(false),isRepair(false),costOfRepair(costOfRepair) {}

    /**
     * @brief Check the capacity of the utility.
     * @return The current capacity of the utility.
     */
    virtual void checkCapacity() const ;

    /**
     * @brief Shed the utility, temporarily shutting it down.
     */
     virtual void shed();

    /**
     * @brief Break the utility, making it non-functional.
     */
     virtual void breakUtility();

    /**
     * @brief Repair the utility, making it functional again.
     */
     virtual void repair();

    virtual ~Utilities() = default;

    UtilityType getType() const { return type; }
    bool isShedding() const { return shedding; }
    bool isBroken() const { return isRepair; }
};

#endif // UTILITIES_H


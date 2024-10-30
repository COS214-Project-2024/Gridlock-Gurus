#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

/**
 * @brief Abstract class representing a utility.
 */
class Utilities {
protected:
    std::string type;
    int maxProduction;
    bool shedding;
    bool isRepair;
    int costOfRepair;

public:
    /**
     * @brief Default constructor for Utilities.
     */
    Utilities(std::string type, int maxProduction, int costOfRepair);

    /**
     * @brief Check the capacity of the utility.
     * @return The current capacity of the utility.
     */
    virtual void checkCapacity() const;

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
};

#endif // UTILITIES_H


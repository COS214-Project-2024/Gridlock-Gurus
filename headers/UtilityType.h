#ifndef UTILITYTYPE_H
#define UTILITYTYPE_H
#include <iostream>
#include <string>
#include <ostream>

/**
 * @enum UtilityType
 * @brief Enum representing types of utilites in the Utility system.
 */

enum class UtilityType {
    Power,
    Sanitation,
    Water,
};

/*std::ostream& operator<<(std::ostream& os, UtilityType type) {
    switch (type) {
        case UtilityType::Power:            os << "Power"; break;
        case UtilityType::Sanitation:       os << "Sanitaton"; break;
        case UtilityType::Water:            os << "Water"; break;
        default:                            os << "Utility"; break;
    }
    return os;
}*/

#endif // UTILITYTYPE_H

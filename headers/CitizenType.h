#ifndef CITIZENTYPE_H
#define CITIZENTYPE_H
#include <iostream>
#include <string>
#include <ostream>

/**
 * @brief Enum representing different types of citizens.
 */
enum class CitizenType {
    Citizen,     ///< Represents a general citizen.
    Worker,      ///< Represents a citizen who is employed.
    Retired      ///< Represents a retired citizen.
};

#endif // CITIZENTYPE_H

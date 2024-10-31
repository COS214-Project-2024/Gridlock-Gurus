#include <iostream>
#include <string>

enum class BuildingType {
    Residential,
    Shop,
    Factory,
    Office,
    Bank
};

// Overload operator<< to allow printing of BuildingType
std::ostream& operator<<(std::ostream& os, BuildingType type) {
    switch (type) {
        case BuildingType::Residential: os << "Residential"; break;
        case BuildingType::Shop:        os << "Shop"; break;
        case BuildingType::Factory:    os << "Factory"; break;
        case BuildingType::Office:     os << "Office"; break;
        case BuildingType::Bank:       os << "Bank"; break;
        default:                       os << "Unknown"; break;
    }
    return os;
}



#include <iostream>
#include <string>

enum class BuildingType {
    Residential,
    Shop,
    BrickFactory,
    SteelFactory,
    WoodFactory,
    Office,
    Bank,
    Flat,
    Estate,
    House,
};

// Overload operator<< to allow printing of BuildingType
std::ostream& operator<<(std::ostream& os, BuildingType type) {
    switch (type) {
        case BuildingType::Residential: os << "Residential"; break;
        case BuildingType::Shop:        os << "Shop"; break;
        case BuildingType::BrickFactory:os << "Brick Factory"; break;
        case BuildingType::WoodFactory: os << "Wood Factory"; break;
        case BuildingType::SteelFactory:os << "Steel Factory"; break;

        case BuildingType::Office:     os << "Office"; break;
        case BuildingType::Bank:       os << "Bank"; break;
        default:                       os << "Unknown"; break;
    }
    return os;
}



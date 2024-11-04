#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include <memory>

class BuildingFactory {
    
    public:
        std::shared_ptr<TaxAuthority> taxAuthority;

        BuildingFactory(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {}

        virtual ~BuildingFactory() = default;

        void startConstruction() {
            
        }

        /**
        * @brief Creates a building of a specific type.
        * @param type The type of building to create.
        * @return Pointer to the created Building object.
        * Factory Method function, which must be implemented by concrete factory subclasses.
        */
        virtual Building* createBuilding(const std::string& name,BuildingType type, Citizen& owner) = 0;


};

#endif // BUILDINGFACTORY_H

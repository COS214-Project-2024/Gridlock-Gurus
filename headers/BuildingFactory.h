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

        virtual Building* createBuilding(BuildingType type, Citizen& owner) = 0;


};

#endif // BUILDINGFACTORY_H

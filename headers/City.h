#ifndef CITY_H
#define CITY_H

#include "Government.h"
#include "BuildingCollection.h"
#include "TaxAuthority.h"
#include "FactoryFactory.h"
#include "LandmarkFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "ServiceFactory.h"
#include <memory>

/**
 * @brief Represents the entire city, managing citizens, buildings, and services.
 *
 * Subject in the Observer pattern, notifying its observers (Government) about changes in the state.
 */
class City {
private:
    Government& government;  ///< Pointer to the government managing the city.
    //BuildingCollection* buildings;  ///< Collection of buildings in the city.

    std::shared_ptr<TaxAuthority> taxAuthority;

    FactoryFactory* factory_factory;
    LandmarkFactory* landmark_factory;
    ResidentialFactory* residential_factory;
    CommercialFactory* commercial_factory;
    ServiceFactory* service_factory;
    int happiness;

public:
    /**
     * @brief Constructs a new City object.
     */
    City(Government& gov,std::shared_ptr<TaxAuthority> taxAuth): government(gov), taxAuthority(taxAuth){
        this->factory_factory = new FactoryFactory(taxAuth);
        this->landmark_factory = new LandmarkFactory(taxAuth);
        this->residential_factory = new ResidentialFactory(taxAuth);
        this->commercial_factory = new CommercialFactory(taxAuth);
        this->service_factory = new ServiceFactory(taxAuth);

    };
    
    /**
     * @brief Destroys the City object.
     */
     ~City(){
        delete factory_factory;
        delete landmark_factory;
        delete residential_factory;
        delete commercial_factory;
        delete service_factory;
    }

    /**
     * @brief Adds an observer (Government) to the city.
     * @param observer The observer to be added.
     */
    void addObserver(Government* observer);

    /**
     * @brief Removes an observer (Government) from the city.
     * @param observer The observer to be removed.
     */
    void removeObserver(Government* observer);

    /**
     * @brief Notifies all observers of a change in the city's state.
     *
     * Observer pattern -> updating observers when the city's state changes.
     */
    void notifyObservers();

    /**
     * @brief Adds a new building to the city's collection of buildings.
     */
    void addBuilding(Building& building){}

    /**
     * @brief Updates citizen happiness based on city conditions.
     */
    void citizenHappiness();

    /**
     * @brief Sets the state of citizen happiness in the city.
     * @param citizenHappiness The new citizen happiness level.
     */
    void setState(int citizenHappiness);

    /**
     * @brief Gets the current state of citizen happiness in the city.
     * @return The current citizen happiness level.
     */
    int getState() const;

    void removeLastBuilding(){}

    int getCitizenHappiness() {
        return happiness;
    }

    void setCitizenHappiness(int happiness) {
        this->happiness = happiness;
    }

};

#endif // CITY_H

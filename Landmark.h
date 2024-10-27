#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

/**
 * @brief Represents a landmark in the city.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and represents a notable landmark structure within the city.
 */
class Landmark : public Building {
private:
     string name;
public:
    /**
     * @brief Constructs a new Landmark building.
     * @param cost The construction cost of the landmark.
     * @param location The location of the landmark.
     * @param resources Pointer to the resources the landmark uses.
     * @param size The size of the landmark.
     * @param owner Pointer to the owner of the landmark.
     * @param taxAuthority Pointer to the tax authority associated with the landmark.
     */
    Landmark(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority, string name);  ///< Constructor

    /**
     * @brief Destroys the Landmark building.
     */
    virtual ~Landmark() = default;  ///< Destructor

    /**
     * @brief Pays taxes for the landmark building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
    void payTax(int amount, Citizen* owner) override;

    /**
     * @brief Gets details about the landmark building.
     * @return A string containing details about the landmark.
     */
    std::string getDetails() override;
};

#endif // LANDMARK_H
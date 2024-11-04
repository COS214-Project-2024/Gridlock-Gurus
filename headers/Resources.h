#ifndef RESOURCES_H
#define RESOURCES_H

/**
 * @class Resources
 * @brief Manages the energy, water, and sanitation resources of a city.
 */
class Resources {
private:
    int energy;                 ///< Energy consumption.
    int water;                  ///< Water consumption.
    bool sanitationAvailable;   ///< Availability of sanitation services.

public:
    /**
     * @brief Constructs a new Resources object.
     * 
     * @param energy Initial energy consumption.
     * @param water Initial water consumption.
     * @param sanitationAvailable Availability of sanitation services.
     */
    Resources(int energy, int water, bool sanitationAvailable);

    /**
     * @brief Destroys the Resources object.
     */
    ~Resources() = default;

    /**
     * @brief Manages the consumption of energy and water resources.
     * @param energyUsed The amount of energy used.
     * @param waterUsed The amount of water used.
     */
    void manageConsumption(int energyUsed, int waterUsed);

    /**
     * @brief Gets the power consumption.
     * @return The current power consumption.
     */
    int getPowerConsumption() const {
        return energy;
    }

    /**
     * @brief Gets the water consumption.
     * @return The current water consumption.
     */
    int getWaterConsumption() const {
        return water;
    }
};

#endif // RESOURCES_H
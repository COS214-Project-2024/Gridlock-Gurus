#ifndef RESOURCES_H
#define RESOURCES_H

/**
 * @brief Manages the resources of the city.
 */
class Resources {
private:
    int energy;
    int water;
    bool sanitationAvailable;

public:
    /**
     * @brief Constructor for Resources.
     */
    Resources(int energy, int water, bool sanitationAvailable);

    ~Resources() = default;

    /**
     * @brief Manages the consumption of resources.
     */

    void manageConsumption(int energyUsed, int waterUsed);


    int getPowerConsumption() const {
        return energy;
    }

    int getWaterConsumption() const {
        return water;
    }
};

#endif // RESOURCES_H

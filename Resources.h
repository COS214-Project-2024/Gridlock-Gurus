#ifndef RESOURCES_H
#define RESOURCES_H

/**
 * @brief Manages the resources of the city.
 */
class Resources {
private:
    int energy;
    int water;
    bool sanitation;

public:
    /**
     * @brief Constructor for Resources.
     */
    Resources();

    virtual ~Resources();

    /**
     * @brief Manages the consumption of resources.
     */
    void manageConsumption();
};

#endif // RESOURCES_H

#ifndef RESOURCES_H
#define RESOURCES_H


class Resources {
private:
    int energy;
    int water;
    bool sanitationAvailable;

public:
    Resources(int energy, int water, bool sanitationAvailable);

    ~Resources() = default;

    void manageConsumption(int energyUsed, int waterUsed);


    int getPowerConsumption() const {
        return energy;
    }

    int getWaterConsumption() const {
        return water;
    }
};

#endif // RESOURCES_H

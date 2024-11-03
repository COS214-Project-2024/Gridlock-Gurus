#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H
#include <vector>
#include <memory>

class Building;

class BuildingIterator {

public:

    BuildingIterator(std::vector<Building*>& buildings, size_t pos) : buildings(buildings), position(pos){}

    ~BuildingIterator() = default;

    Building* operator*() const ;

    BuildingIterator& operator++();

    bool operator!=(const BuildingIterator& other) const;

    bool operator==(const BuildingIterator& other) const;

private:
    std::vector<Building*>& buildings;
    size_t position;
};

#endif // BUILDINGITERATOR_H

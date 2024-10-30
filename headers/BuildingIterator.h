#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H
#include <vector>
#include <memory>

class Building;

/**
* @class BuildingIterator
* @brief Provides functionality to iterate through BuildingCollection.
*/
class BuildingIterator {
    friend class Building;

public:
    using BuildingPtr = std::shared_ptr<Building>;

    /**
     * @brief Constructs an iterator for the given collection of buildings.
     * @param buildings Reference to the vector of buildings.
     * @param pos Initial position of the iterator.
     */ 
    BuildingIterator(std::vector<BuildingPtr>& buildings, size_t pos) : buildings(buildings), position(pos){}
    
    /**
     * @brief Destroys the BuildingIterator object.
     */
    ~BuildingIterator() = default;

    /**
     * @brief Dereference operator to access the current building.
     * @return Shared pointer to the current building.
     */
    BuildingPtr operator*() const ;

    /**
     * @brief Prefix increment operator to advance to the next building.
     * @return Reference to the incremented iterator.
     */
    BuildingIterator& operator++();

    /**
     * @brief Inequality operator to compare two iterators.
     * @param other The iterator to compare with.
     * @return True if iterators are not equal, false otherwise.
     */
    bool operator!=(const BuildingIterator& other) const;

    /**
     * @brief Equality operator to compare two iterators.
     * @param other The iterator to compare with.
     * @return True if iterators are equal, false otherwise.
     */
    bool operator==(const BuildingIterator& other) const;

private:
    std::vector<BuildingPtr>& buildings;    ///< Reference to the vector of buildings.
    size_t position;                        ///< Current position of the iterator.
};

#endif // BUILDINGITERATOR_H

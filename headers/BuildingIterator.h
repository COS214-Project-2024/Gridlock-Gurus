#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H
#include <vector>
#include <memory>

/**
 * @brief Forward declaration of building class.
 */
class Building;

/**
 * @brief Iterator for a collection of Building objects.
 */
class BuildingIterator {
public:
    /**
     * @brief Constructs a new BuildingIterator object.
     * @param buildings Vector of Building pointers to iterate over.
     * @param pos Initial position in the collection.
     */
    BuildingIterator(std::vector<Building*>& buildings, size_t pos) : buildings(buildings), position(pos) {}

    /**
     * @brief Destroys the BuildingIterator object.
     */
    ~BuildingIterator() = default;

    /**
     * @brief Dereferences the iterator to access the current Building.
     * @return Pointer to the current Building.
     */
    Building* operator*() const;

    /**
     * @brief Advances the iterator to the next building.
     * @return Reference to the updated iterator.
     */
    BuildingIterator& operator++();

    /**
     * @brief Checks if two iterators are not equal.
     * @param other The other iterator to compare.
     * @return True if not equal, otherwise false.
     */
    bool operator!=(const BuildingIterator& other) const;

    /**
     * @brief Checks if two iterators are equal.
     * @param other The other iterator to compare.
     * @return True if equal, otherwise false.
     */
    bool operator==(const BuildingIterator& other) const;

private:
    std::vector<Building*>& buildings; ///< Reference to the vector of buildings.
    size_t position; ///< Current position in the vector.
};

#endif // BUILDINGITERATOR_H

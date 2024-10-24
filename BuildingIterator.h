#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

class Building;

/**
 * @brief Iterator for iterating over buildings in a collection.
 *
 * ConcreteIterator participant in the Iterator design pattern, providing a way to traverse buildings in a BuildingCollection.
 */
class BuildingIterator {
    friend class Building;
public:
    /**
     * @brief Constructs a new BuildingIterator object.
     */
    BuildingIterator();
    
    /**
     * @brief Destroys the BuildingIterator object.
     */
    virtual ~BuildingIterator();

    /**
     * @brief Returns the next building in the collection.
     * @return Pointer to the next building.
     */
    Building* next();

    /**
     * @brief Checks if there are more buildings to iterate over.
     * @return True if there are more buildings, false otherwise.
     */
    bool hasNext();
};

#endif // BUILDINGITERATOR_H

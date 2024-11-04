#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * @class NameGenerator
 * @brief Generates random names and IDs.
 */
class NameGenerator {
private:
    std::vector<std::string> firstNames;
    std::vector<std::string> lastNames;

    /**
     * @brief Private constructor for singleton pattern.
     */
    NameGenerator();

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    NameGenerator(const NameGenerator&) = delete;

    /**
     * @brief Deleted assignment operator to prevent copying.
     */
    void operator=(const NameGenerator&) = delete;

public:
    /**
     * @brief Gets the singleton instance of NameGenerator.
     * @return The singleton instance.
     */
    static NameGenerator& getInstance();

    /**
     * @brief Generates a random name.
     * @return A random name.
     */
    std::string getRandomName();

    /**
     * @brief Generates a random ID with a specified number of digits.
     * @param numDigits The number of digits in the generated ID.
     * @return A random ID.
     */
    int getRandomID(int numDigits = 8);
};

#endif // NAMEGENERATOR_H
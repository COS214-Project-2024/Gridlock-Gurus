#include "NameGenerator.h"
#include <sstream>
#include <cmath>

/**
 * @brief Constructs a NameGenerator and initializes lists of first and last names.
 */
NameGenerator::NameGenerator() {
    std::srand(std::time(0));

    firstNames = { "Jane", "Alex", "Chris", "Taylor", "James", "John", "Robert", "Michael", "William", "David", "Richard", "Charles", "Joseph", "Thomas", "Christopher", "Daniel", "Paul", "Mark", "Donald", "George", "Kenneth", "Steven", "Edward", "Brian", "Ronald", "Anthony", "Kevin", "Jason", "Jeff", "Mary", "Patricia", "Linda", "Barbara", "Elizabeth", "Jennifer", "Maria", "Susan", "Margaret", "Dorothy", "Lisa", "Nancy", "Karen", "Betty", "Helen", "Sandra", "Donna", "Carol", "Ruth", "Sharon", "Michelle", "Laura", "Sarah", "Kimberly", "Deborah" };
    lastNames = { "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez", "Hernandez", "Lopez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin" };
}

/**
 * @brief Gets the singleton instance of NameGenerator.
 * @return Reference to the singleton NameGenerator instance.
 */
NameGenerator& NameGenerator::getInstance() {
    static NameGenerator instance;
    return instance;
}

/**
 * @brief Generates a random name by combining a first name and a last name.
 * @return Randomly generated full name in the format "First Last".
 */
std::string NameGenerator::getRandomName() {
    std::string firstName = firstNames[rand() % firstNames.size()];
    std::string lastName = lastNames[rand() % lastNames.size()];
    return firstName + " " + lastName;
}

/**
 * @brief Generates a random ID with a specified number of digits.
 * @param numDigits Number of digits for the ID.
 * @return Randomly generated ID with the specified number of digits.
 */
int NameGenerator::getRandomID(int numDigits) {
    int min = std::pow(10, numDigits - 1);
    int max = std::pow(10, numDigits) - 1;
    return min + rand() % (max - min + 1);
}

#include "NameGenerator.h"

NameGenerator::NameGenerator() {
    std::srand(std::time(0));

    firstNames = { "Jane", "Alex", "Chris", "Taylor", "James", "John", "Robert", "Michael", "William", "David", "Richard", "Charles", "Joseph", "Thomas", "Christopher", "Daniel", "Paul", "Mark", "Donald", "George", "Kenneth", "Steven", "Edward", "Brian", "Ronald", "Anthony", "Kevin", "Jason", "Jeff", "Mary", "Patricia", "Linda", "Barbara", "Elizabeth", "Jennifer", "Maria", "Susan", "Margaret", "Dorothy", "Lisa", "Nancy", "Karen", "Betty", "Helen", "Sandra", "Donna", "Carol", "Ruth", "Sharon", "Michelle", "Laura", "Sarah", "Kimberly", "Deborah" };
    lastNames = { "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez", "Hernandez", "Lopez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin" };
}

NameGenerator& NameGenerator::getInstance() {
    static NameGenerator instance;
    return instance;
}

std::string NameGenerator::getRandomName() {
    std::string firstName = firstNames[rand() % firstNames.size()];
    std::string lastName = lastNames[rand() % lastNames.size()];
    return firstName + " " + lastName;
}
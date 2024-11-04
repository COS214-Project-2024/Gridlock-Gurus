#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class NameGenerator {
private:
    std::vector<std::string> firstNames;
    std::vector<std::string> lastNames;

    NameGenerator();
    NameGenerator(const NameGenerator&) = delete;
    void operator=(const NameGenerator&) = delete;

public:
    static NameGenerator& getInstance();
    std::string getRandomName();
    int getRandomID(int numDigits = 8);

};

#endif // NAMEGENERATOR_H
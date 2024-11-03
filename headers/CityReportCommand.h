#ifndef CITYREPORTCOMMAND_H
#define CITYREPORTCOMMAND_H
#include <memory>
#include <string>
#include "Command.h"
#include "City.h"

class City;

class CityReportCommand : public Command {
    std::string& temp;
public:
    /**
     * @brief Constructs a new Command object.
     */
    CityReportCommand(std::shared_ptr<City> city,std::string& temp) : Command(city), temp(temp){
    }

    /**
     * @brief Destroys the Command object.
     */
     ~CityReportCommand() = default;

    /**
     * @brief Executes the command.
     */
     void execute() override {
        city->generateReport(temp);
     }
};

#endif // CITYREPORTCOMMAND_H

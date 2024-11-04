#ifndef CITYREPORTCOMMAND_H
#define CITYREPORTCOMMAND_H
#include <memory>
#include <string>
#include "Command.h"
#include "City.h"

class City;

/**
 * @brief Command to generate a report for a city.
 */
class CityReportCommand : public Command {
    std::string& temp; ///< Reference to a string to store the report.

public:
    /**
     * @brief Constructs a CityReportCommand object.
     * @param city Pointer to the city for which the report will be generated.
     * @param temp Reference to a string that will store the generated report.
     */
    CityReportCommand(std::shared_ptr<City> city, std::string& temp) : Command(city), temp(temp) {}

    /**
     * @brief Default destructor.
     */
    ~CityReportCommand() = default;

    /**
     * @brief Executes the command to generate the city report.
     */
    void execute() override {
        city->generateReport(temp);
    }
};

#endif // CITYREPORTCOMMAND_H

#include "ResetCommand.h"
#include "BuildCommand.h"

void ResetCommand::execute() {
    city = std::make_shared<City>();
    std::shared_ptr<City> city = std::make_shared<City>();
    BuildCommand newBuild(city, director, BuildingType::House);
    newBuild.execute();
    std::cout<<"New city created"<<std::endl;
}

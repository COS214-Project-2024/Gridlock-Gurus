#include "ResetCommand.h"
#include "BuildCommand.h"

void ResetCommand::execute() {
    delete city;
    city = new City();
    BuildCommand newBuild(*city, director, BuildingType::House);
    newBuild.execute();
    std::cout<<"New city created"<<std::endl;
}

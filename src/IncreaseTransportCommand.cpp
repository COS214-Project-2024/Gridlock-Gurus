#include "IncreaseTransportCommand.h"

void IncreaseTransportCommand::execute() {
    city->increaseTransport(type);
}

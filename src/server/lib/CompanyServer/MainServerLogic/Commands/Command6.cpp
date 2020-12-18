#include "Command6.h"

boost::property_tree::ptree Command6::execute(std::shared_ptr<Controller> controller) {
    return controller->command6(commandParams);
}

Command6::Command6(boost::property_tree::ptree &params) : BaseCommand("GetLog") {
    commandParams = params;
}

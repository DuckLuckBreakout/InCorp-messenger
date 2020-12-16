#include "Command1.h"

boost::property_tree::ptree Command1::execute(std::shared_ptr<Controller> controller) {
    return controller->command1(commandParams);
}

Command1::Command1(boost::property_tree::ptree &params) {
    commandParams = params;
}

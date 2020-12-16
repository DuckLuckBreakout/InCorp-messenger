#include "Command5.h"

boost::property_tree::ptree Command5::execute(std::shared_ptr<Controller> controller) {
    return controller->command5(commandParams);
}

Command5::Command5(boost::property_tree::ptree &params) {
    commandParams = params;
}

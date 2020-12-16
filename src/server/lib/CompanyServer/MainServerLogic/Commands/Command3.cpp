#include "Command3.h"

boost::property_tree::ptree Command3::execute(std::shared_ptr<Controller> controller) {
    return controller->command3(commandParams);
}

Command3::Command3(boost::property_tree::ptree &params) {
    commandParams = params;
}

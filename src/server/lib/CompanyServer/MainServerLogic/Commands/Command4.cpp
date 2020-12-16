#include "Command4.h"

boost::property_tree::ptree Command4::execute(std::shared_ptr<Controller> controller) {
    return controller->command4(commandParams);
}

Command4::Command4(boost::property_tree::ptree &params) {
    commandParams = params;
}

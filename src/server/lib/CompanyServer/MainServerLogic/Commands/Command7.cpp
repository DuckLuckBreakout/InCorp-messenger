#include "Command7.h"

boost::property_tree::ptree Command7::execute(std::shared_ptr<Controller> controller) {
    return controller->command7(commandParams);
}

Command7::Command7(boost::property_tree::ptree &params) : BaseCommand("") {
commandParams = params;
}

#include "Command.h"

boost::property_tree::ptree Command::execute(std::shared_ptr<Controller> controller) {
    return controller->command(commandParams);
}

Command::Command(boost::property_tree::ptree &params) : BaseCommand("") {
commandParams = params;
}

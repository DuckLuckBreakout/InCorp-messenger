#include "Command2.h"

boost::property_tree::ptree Command2::execute(std::shared_ptr<Controller> controller) {
    return controller->command2(commandParams);
}

Command2::Command2(boost::property_tree::ptree &params) : BaseCommand("GetSelectChatRoom") {
    commandParams = params;
}

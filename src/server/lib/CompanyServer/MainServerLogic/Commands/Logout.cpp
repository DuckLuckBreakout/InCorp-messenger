#include "Logout.h"


boost::property_tree::ptree Logout::execute(std::shared_ptr<Controller> controller) {
    return controller->logoutUser(commandParams);
}

Logout::Logout(boost::property_tree::ptree &params) : BaseCommand("Logout") {
    commandParams = params;
}


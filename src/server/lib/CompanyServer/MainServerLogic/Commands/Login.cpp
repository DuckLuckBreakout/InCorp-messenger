#include "Login.h"

boost::property_tree::ptree Login::execute(std::shared_ptr<Controller> controller) {
    return controller->loginUser(commandParams);
}

Login::Login(boost::property_tree::ptree &params) {
    commandParams = params;
}

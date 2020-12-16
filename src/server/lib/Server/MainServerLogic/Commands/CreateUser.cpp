#include "CreateUser.h"

boost::property_tree::ptree CreateUser::execute(std::shared_ptr<Controller> controller) {
    return controller->createUser(commandParams);
}

CreateUser::CreateUser(boost::property_tree::ptree &params) {
    commandParams = params;
}

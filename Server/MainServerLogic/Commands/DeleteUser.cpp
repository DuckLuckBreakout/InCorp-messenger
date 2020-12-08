#include "DeleteUser.h"

boost::property_tree::ptree DeleteUser::execute(std::shared_ptr<Controller> controller) {
    return controller->deleteUser(commandParams);
}

DeleteUser::DeleteUser(boost::property_tree::ptree &params) {
    commandParams = params;
}

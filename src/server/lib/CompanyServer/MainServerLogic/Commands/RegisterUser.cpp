#include "RegisterUser.h"

boost::property_tree::ptree RegisterUser::execute(std::shared_ptr<Controller> controller) {
    return controller->registerUser(commandParams);
}

RegisterUser::RegisterUser(boost::property_tree::ptree &params) : BaseCommand("") {
    commandParams = params;
}

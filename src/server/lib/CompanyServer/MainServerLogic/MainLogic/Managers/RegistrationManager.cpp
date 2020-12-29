#include "RegistrationManager.h"

boost::property_tree::ptree RegistrationManager::deleteUser(boost::property_tree::ptree &params) {
    std::string login = params.get<std::string>("body.login");
    if (dbConnector.userIsRegistered(login)) {
        dbConnector.deleteUser(params);
        params.add("status", "true");
        params.add("error", "");
    }
    else {
        params.add("error", "User not registered");
        params.add("status", "false");

    }
    return params;
}

boost::property_tree::ptree RegistrationManager::registerUser(boost::property_tree::ptree &params) {
    dbConnector.createUser(params);
    params.put("command", "-10");

    params.add("status", "true");
    params.add("error", "");
    return params;
}


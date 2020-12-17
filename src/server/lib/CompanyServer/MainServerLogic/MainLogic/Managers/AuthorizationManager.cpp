#include "AuthorizationManager.h"


boost::property_tree::ptree AuthorizationManager::loginUser(boost::property_tree::ptree &params) {
    std::string token = params.get<std::string>("body.login");
    if (dbConnector.userIsRegistered(token)) {
        dbConnector.authorizeUser(token);
        dbConnector.getUserInfo(params);
        params.add("status", "true");
        params.add("error", "");
        params.add("body.ip", "192.168.1.115");
        params.add("body.port", "5555");
    }
    else {
        params.add("status", "false");
        params.add("error", "Not registered");
    }
    return params;
}

boost::property_tree::ptree AuthorizationManager::logoutUser(boost::property_tree::ptree &params) {
    std::string token = params.get<std::string>("body.login");

    if (dbConnector.userIsAuthorized(token)) {
        dbConnector.logoutUser(token);
        params.add("status", "true");
        params.add("error", "");
    }
    else {
        params.add("error", "User not login");
        params.add("status", "false");
    }
    return params;
}

boost::property_tree::ptree AuthorizationManager::deleteUser(boost::property_tree::ptree &params) {
    std::string token = params.get<std::string>("body.login");
    if (dbConnector.userIsRegistered(token)) {
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


boost::property_tree::ptree AuthorizationManager::createUser(boost::property_tree::ptree &params) {
    std::string token = params.get<std::string>("body.login");
    if (!dbConnector.userIsRegistered(token)) {
        dbConnector.createUser(params);
        params.add("status", "true");
        params.add("error", "");
    }
    else {
        params.add("error", "User already registered");
        params.add("status", "true");
    }
    return params;
}

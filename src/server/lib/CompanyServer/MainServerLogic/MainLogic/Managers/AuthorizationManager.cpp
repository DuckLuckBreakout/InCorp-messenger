#include "AuthorizationManager.h"


boost::property_tree::ptree AuthorizationManager::loginUser(boost::property_tree::ptree &params) {
    auto login = params.get<std::string>("body.login");
    if (dbConnector.userIsRegistered(login)) {
        std::cout << "TUT";
        dbConnector.authorizeUser(login);
        dbConnector.getUserInfo(params);
        params.add("status", "true");
        params.add("error", "");
        params.add("body.ip", "192.168.0.70");
        params.add("body.port", "5556");
    }
    else {
        params.add("status", "false");
        params.add("error", "Not registered");
    }
    return params;
}

boost::property_tree::ptree AuthorizationManager::logoutUser(boost::property_tree::ptree &params) {
    auto login = params.get<std::string>("body.login");

    if (dbConnector.userIsAuthorized(login)) {
        dbConnector.logoutUser(login);
        params.add("status", "true");
        params.add("error", "");
    }
    else {
        params.add("error", "User not login");
        params.add("status", "false");
    }
    return params;
}

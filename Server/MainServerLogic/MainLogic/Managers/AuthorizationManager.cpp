#include "AuthorizationManager.h"


boost::property_tree::ptree AuthorizationManager::loginUser(boost::property_tree::ptree &params) {
    std::string token = params.get<std::string>("body.token");
    std::cout << token << std::endl;
    if (dbConnector.userIsRegistered(token)) {
        dbConnector.authorizeUser(token);
        params.add("status", "true");
        params.add("body.userId", 1234);
        params.add("body.chatsId", "[1, 2, 3]");
        params.add("body.firstName", "Ivan");
        params.add("body.lastName", "Kovalenko");
        params.add("error", "");
        params.put("body.role", "employee");

    }
    else
        params.add("status", "false");
    return params;
}

boost::property_tree::ptree AuthorizationManager::logoutUser(boost::property_tree::ptree &params) {
    std::string token = params.get<std::string>("body.token");
    std::cout << token << std::endl;

    if (dbConnector.userIsAuthorized(token)) {
        std::cout << "logout success" << std::endl;
        dbConnector.logoutUser(token);
        params.add("status", "");
    }
    else {
        std::cout << "user not login" << std::endl;
        params.add("status", "User not login");
        params.add("body.role", "employee");
    }
    return params;
}

boost::property_tree::ptree AuthorizationManager::deleteUser(boost::property_tree::ptree &params) {
    std::string token = params.get<std::string>("body.userToken");
    if (dbConnector.userIsRegistered(token)) {
        std::cout << "delete success" << std::endl;
        dbConnector.deleteUser(params);
        params.add("status", "");
    }
    else {
        std::cout << "user not registered" << std::endl;
        params.add("status", "User not registered");
    }
    return params;
}



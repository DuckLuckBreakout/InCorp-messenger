#include "ChatManager.h"

boost::property_tree::ptree ChatManager::updateChats(boost::property_tree::ptree &params) {
    return params;
}

boost::property_tree::ptree ChatManager::deleteChat(boost::property_tree::ptree &params) {
    dbConnector.deleteChat(params);
    params.add("status", "true");
    params.add("error", "");
    return params;
}

boost::property_tree::ptree ChatManager::createChat(boost::property_tree::ptree &params) {
    dbConnector.createChat(params);
    params.add("status", "true");
    params.add("error", "");
    return params;
}

boost::property_tree::ptree ChatManager::sendMessage(boost::property_tree::ptree &params) {

    if (true) {
        dbConnector.addMessage(params);
        params.add("status", "true");
        params.add("body.isChecked", "false");
        params.add("error", "");
    }
    else {
        params.add("status", "false");
        params.add("error", "User not login");
    }

    return params;
}

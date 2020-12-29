#include "InfoManager.h"

boost::property_tree::ptree InfoManager::getMessageAuthorInfo(boost::property_tree::ptree &params) {
    dbConnector.getMessageAuthorInfo(params);
    params.add("status", "true");
    params.add("error", "");
    return params;
}

boost::property_tree::ptree InfoManager::getChatInfo(boost::property_tree::ptree &params) {
    dbConnector.getChatInfo(params);

    params.add("status", "true");
    params.add("error", "");

    params.put("command", "21");
    return params;
}

boost::property_tree::ptree InfoManager::getUserChatsPreview(boost::property_tree::ptree &params) {
    if (1) {
        dbConnector.getUserChatsPreview(params);
        params.add("status", "true");
        params.add("error", "");

    }
    return params;
}
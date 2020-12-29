#include <boost/property_tree/json_parser.hpp>
#include "ChatManager.h"


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
    if (1) {
        params.add("body.isChecked", "false");
        dbConnector.addMessage(params);
        params.add("status", "true");
        params.add("error", "");
    }
    else {
        params.add("status", "false");
        params.add("error", "User not login");
    }

    return params;
}

boost::property_tree::ptree ChatManager::getChatMessages(boost::property_tree::ptree &params) {
    dbConnector.getChatMessages(params);
    params.add("status", "true");
    params.add("error", "");
    return params;
}

boost::property_tree::ptree ChatManager::getChatLastMessage(boost::property_tree::ptree &params) {
    boost::property_tree::ptree lastMessage = dbConnector.getChatLastMessage(params.get<int>("body.chatId"));
    params.add("status", "true");
    params.add("error", "");

    params.put_child("body", lastMessage);
    return params;
}
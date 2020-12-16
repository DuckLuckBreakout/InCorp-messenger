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

boost::property_tree::ptree ChatManager::command1(boost::property_tree::ptree &params) {
    if (1) {
        dbConnector.getUserChatsPreview(params);
        params.add("status", "true");
        params.add("error", "");

    }
    return params;
}
boost::property_tree::ptree ChatManager::command2(boost::property_tree::ptree &params) {

    dbConnector.getChatInfo(params);

    params.add("status", "true");
    params.add("error", "");

    params.put("command", "21");
    return params;
}
boost::property_tree::ptree ChatManager::command3(boost::property_tree::ptree &params) {
    dbConnector.getChatMessages(params);
    params.add("status", "true");
    params.add("error", "");
    return params;
}
boost::property_tree::ptree ChatManager::command4(boost::property_tree::ptree &params) {
    boost::property_tree::ptree lastMessage = dbConnector.getChatLastMessage(params.get<int>("body.chatId"));
    params.add("status", "true");
    params.add("error", "");

    params.put_child("body", lastMessage);
    return params;
}
boost::property_tree::ptree ChatManager::command5(boost::property_tree::ptree &params) {
    dbConnector.getMessageAuthorInfo(params);
    params.add("status", "true");
    params.add("error", "");
    return params;
}
boost::property_tree::ptree ChatManager::command6(boost::property_tree::ptree &params) {
    return params;
}
boost::property_tree::ptree ChatManager::command7(boost::property_tree::ptree &params) {
    return params;
}
boost::property_tree::ptree ChatManager::command8(boost::property_tree::ptree &params) {
    return params;
}


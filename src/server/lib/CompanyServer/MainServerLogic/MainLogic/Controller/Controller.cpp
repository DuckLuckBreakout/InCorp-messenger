#include <boost/property_tree/ptree.hpp>
#include "Controller.h"


Controller::Controller() :
        chatManager(new ChatManager),
        authorizationManager(new AuthorizationManager),
        registrationManager(new RegistrationManager),
        commandsManager(new CommandsManager),
        logsManager(new LogsManager),
        infoManager(new InfoManager) {
}

boost::property_tree::ptree Controller::loginUser(boost::property_tree::ptree &params) {
    return authorizationManager->loginUser(params);
}

boost::property_tree::ptree Controller::logoutUser(boost::property_tree::ptree &params) {
    return authorizationManager->logoutUser(params);
}

boost::property_tree::ptree Controller::updateChats(boost::property_tree::ptree &params) {
    return chatManager->updateChats(params);
}

boost::property_tree::ptree Controller::deleteChat(boost::property_tree::ptree &params) {
    return chatManager->deleteChat(params);
}

boost::property_tree::ptree Controller::createChat(boost::property_tree::ptree &params) {
    return chatManager->createChat(params);
}

boost::property_tree::ptree Controller::sendMessage(boost::property_tree::ptree &params) {
    return chatManager->sendMessage(params);
}

boost::property_tree::ptree Controller::deleteUser(boost::property_tree::ptree &params) {
    return registrationManager->deleteUser(params);
}

boost::property_tree::ptree Controller::getUserChatsPreview(boost::property_tree::ptree &params) {
    return infoManager->getUserChatsPreview(params);
}
boost::property_tree::ptree Controller::getChatInfo(boost::property_tree::ptree &params) {
    return infoManager->getChatInfo(params);
}
boost::property_tree::ptree Controller::getChatMessages(boost::property_tree::ptree &params) {
    return chatManager->getChatMessages(params);
}
boost::property_tree::ptree Controller::getChatLastMessage(boost::property_tree::ptree &params) {
    return chatManager->getChatLastMessage(params);
}
boost::property_tree::ptree Controller::getMessageAuthorInfo(boost::property_tree::ptree &params) {
    return infoManager->getMessageAuthorInfo(params);
}
boost::property_tree::ptree Controller::getServerLogs(boost::property_tree::ptree &params) {
    return logsManager->getServerLogs(params);
}
boost::property_tree::ptree Controller::command(boost::property_tree::ptree &params) {
    return commandsManager->command(params);
}
boost::property_tree::ptree Controller::registerUser(boost::property_tree::ptree &params) {
    return registrationManager->registerUser(params);
}

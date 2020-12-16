#include <boost/property_tree/ptree.hpp>
#include "Controller.h"

// TODO: create all functions of server
// send() using concrete manager
// write() using concrete manager
// loginUser() using concrete manager
// logoutUser() using concrete manager

Controller::Controller() :
        chatManager(new ChatManager),
        authorizationManager(new AuthorizationManager) {

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
    return authorizationManager->deleteUser(params);
}

boost::property_tree::ptree Controller::createUser(boost::property_tree::ptree &params) {
    return authorizationManager->createUser(params);
}

boost::property_tree::ptree Controller::command1(boost::property_tree::ptree &params) {
    return chatManager->command1(params);
}
boost::property_tree::ptree Controller::command2(boost::property_tree::ptree &params) {
    return chatManager->command2(params);
}
boost::property_tree::ptree Controller::command3(boost::property_tree::ptree &params) {
    return chatManager->command3(params);
}
boost::property_tree::ptree Controller::command4(boost::property_tree::ptree &params) {
    return chatManager->command4(params);
}
boost::property_tree::ptree Controller::command5(boost::property_tree::ptree &params) {
    return chatManager->command5(params);
}
boost::property_tree::ptree Controller::command6(boost::property_tree::ptree &params) {
    return chatManager->command6(params);
}
boost::property_tree::ptree Controller::command7(boost::property_tree::ptree &params) {
    return chatManager->command7(params);
}
boost::property_tree::ptree Controller::command8(boost::property_tree::ptree &params) {
    return chatManager->command8(params);
}

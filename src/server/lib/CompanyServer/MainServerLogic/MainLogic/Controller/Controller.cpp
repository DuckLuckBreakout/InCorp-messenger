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

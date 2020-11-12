#include "Controller.h"

// TODO: create all functions of server
// send() using concrete manager
// write() using concrete manager
// loginUser() using concrete manager
// logoutUser() using concrete manager

Controller::Controller() : dbManager(), chatManager(), authorizationManager() {

}

void Controller::loginUser(std::shared_ptr<BaseConnection> &connection, std::string token) {
    authorizationManager->loginUser(connection, token);
}

void Controller::logoutUser(std::shared_ptr<BaseConnection> &connection) {
    authorizationManager->logoutUser(connection);
}

void Controller::updateChats() {
    chatManager->updateChats();
}

void Controller::deleteChat(int chatID) {
    chatManager->deleteChat(chatID);
}

void Controller::createChat() {
    chatManager->createChat();
}

void Controller::sendMessage(std::string message, int chatID) {
    chatManager->sendMessage(message, chatID);
}


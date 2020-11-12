#include "ManagerOptions.h"

void ManagerOptions::login(std::shared_ptr<BaseConnection>& connection,
                           const std::string &token) {
    throw std::runtime_error("exception: user already logged");
}

void ManagerOptions::logout(std::shared_ptr<BaseConnection>& connection) {
    authorizationManager.logout(connection);
}

void ManagerOptions::sendMessage(std::shared_ptr<BaseConnection>& connection,
                                 int chatId, const std::string &message) {
    chatManager.sendMessage(connection, chatId, message);
}

void ManagerOptions::updateChats(std::shared_ptr<BaseConnection>& connection) {
    chatManager.updateChats(connection);
}

void ManagerOptions::createChat(std::shared_ptr<BaseConnection>& connection,
                                const std::string &chatName) {
    chatManager.createChat(connection, chatName);
}

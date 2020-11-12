#include "EmployeeOptions.h"

void EmployeeOptions::login(std::shared_ptr<BaseConnection>& connection,
                            const std::string& token) {
    throw std::runtime_error("exception: user already logged");
}

void EmployeeOptions::logout(std::shared_ptr<BaseConnection>& connection) {
    authorizationManager.logout(connection);
}

void EmployeeOptions::sendMessage(std::shared_ptr<BaseConnection>& connection,
                                  int chatId, const std::string& message) {
    chatManager.sendMessage(connection, chatId, message);
}

void EmployeeOptions::updateChats(std::shared_ptr<BaseConnection>& connection) {
    chatManager.updateChats(connection);
}

void EmployeeOptions::createChat(std::shared_ptr<BaseConnection>& connection,
                                 const std::string& chatName) {
    throw std::runtime_error("exception: user can't create chats");
}

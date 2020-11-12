#include "GuestOptions.h"

void GuestOptions::login(std::shared_ptr<BaseConnection>& connection,
                         const std::string& token) {
    authorizationManager.login(connection, token);
}

void GuestOptions::logout(std::shared_ptr<BaseConnection>& connection) {
    throw std::runtime_error("exception: guest can't logout");
}

void GuestOptions::sendMessage(std::shared_ptr<BaseConnection>& connection,
                               int chatId, const std::string& message) {
    throw std::runtime_error("exception: guest can't send message");
}

void GuestOptions::updateChats(std::shared_ptr<BaseConnection>& connection) {
    throw std::runtime_error("exception: guest can't update chats");
}

void GuestOptions::createChat(std::shared_ptr<BaseConnection>& connection,
                              const std::string& chatName) {
    throw std::runtime_error("exception: guest can't create chat");
}

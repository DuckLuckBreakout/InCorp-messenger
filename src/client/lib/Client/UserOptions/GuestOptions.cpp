#include "GuestOptions.h"

void GuestOptions::sendMessage(const Message& message, int globalId, const std::shared_ptr<BaseCallback> callback,
                               std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't send message");
}

void GuestOptions::getLog(const LogUpdates &logUpdates, int globalId, const std::shared_ptr<BaseCallback> callback,
                          std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't get server log");
}

void GuestOptions::chatUpdate(const ChatUpdates &chatUpdates, int globalId,
                              const std::shared_ptr<BaseCallback> callback,
                              std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't update chats");
}

void GuestOptions::getListChats(const ListChats &listChats, int globalId,
                                const std::shared_ptr<BaseCallback> callback,
                                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't get list of chats");
}

void GuestOptions::getChatRoom(const ChatRoom &chatRoom, int globalId,
                               const std::shared_ptr<BaseCallback> callback,
                               std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't get chat room");
}

void GuestOptions::getChatMessages(const ChatUpdates &chatUpdates, int globalId,
                                   const std::shared_ptr<BaseCallback> callback, std::shared_ptr<BaseClient> client,
                                   std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't get chat messages");
}

void GuestOptions::getLastMessage(const Message &message, int globalId,
                                  const std::shared_ptr<BaseCallback> callback,
                                  std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't get last message");
}

void GuestOptions::getUser(const UserPreview &user, int globalId,
                           const std::shared_ptr<BaseCallback> callback,
                           std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't get user");
}

void GuestOptions::setChatObserver(int chatId, const std::shared_ptr<BaseCallback> callback,
                                   std::shared_ptr<BaseClient> client,
                                   std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't set chat observer");
}

void GuestOptions::sendChatCommand(const Message &message, int globalId, std::shared_ptr<BaseClient> client,
                                   std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't send chat command");
}

void GuestOptions::registration(const UserInfo &authInfo, int globalId, const std::shared_ptr<BaseCallback> callback,
                                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't register new user");
}

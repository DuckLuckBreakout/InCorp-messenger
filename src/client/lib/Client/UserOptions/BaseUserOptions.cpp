#include "BaseUserOptions.h"

void BaseUserOptions::sendMessage(const Message& message, int globalId,
                                  const std::shared_ptr<BaseCallback> callback,
                                  std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::SendMessage, callback);
    Request query(Commands::SendMessage, message.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::authorization(const UserInfo &authInfo, int globalId,
                                    const std::shared_ptr<BaseCallback> callback,
                                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::LogIn, callback);
    Request query(Commands::LogIn, authInfo.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::chatUpdate(const ChatUpdates &chatUpdates, int globalId,
                                 const std::shared_ptr<BaseCallback> callback,
                                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    callbackHolder->addCallback(Commands::SystemUpdate, callback);
}

void BaseUserOptions::getListChats(const ListChats& listChats, int globalId,
                                   const std::shared_ptr<BaseCallback> callback, std::shared_ptr<BaseClient> client,
                                   std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::GetListOfChats, callback);
    Request query(Commands::GetListOfChats, listChats.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::getChatRoom(const ChatRoom &chatRoom, int globalId, const std::shared_ptr<BaseCallback> callback,
                                  std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::GetSelectChatRoom, callback);
    Request query(Commands::GetSelectChatRoom, chatRoom.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::getChatMessages(const ChatUpdates &chatUpdates, int globalId,
                                      const std::shared_ptr<BaseCallback> callback, std::shared_ptr<BaseClient> client,
                                      std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::GetMessagesInChat, callback);
    Request query(Commands::GetMessagesInChat, chatUpdates.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::getLastMessage(const Message &message, int globalId, const std::shared_ptr<BaseCallback> callback,
                                     std::shared_ptr<BaseClient> client,
                                     std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::GetLastMessageInChat, callback);
    Request query(Commands::GetLastMessageInChat, message.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::getUser(const UserPreview &user, int globalId, const std::shared_ptr<BaseCallback> callback,
                              std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::GetUserData, callback);
    Request query(Commands::GetUserData, user.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::setChatObserver(int chatId, const std::shared_ptr<BaseCallback> callback,
                                      std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    callbackHolder->addCallback(Commands::ChatObserver, chatId, callback);
}

void BaseUserOptions::getLog(const LogUpdates &logUpdates, int globalId, const std::shared_ptr<BaseCallback> callback,
                             std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::GetLog, callback);
    Request query(Commands::GetLog, logUpdates.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::sendChatCommand(const Message &message, int globalId, std::shared_ptr<BaseClient> client,
                                      std::shared_ptr<CallbacksHolder> callbackHolder) {
    Request query(Commands::SendChatCommand, message.encode(), globalId, -1);
    client->sendMessage(query.encode());
}

void BaseUserOptions::registration(const UserInfo &authInfo, int globalId,
                                   const std::shared_ptr<BaseCallback> callback, std::shared_ptr<BaseClient> client,
                                   std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::RegistrationUser, callback);
    Request query(Commands::RegistrationUser, authInfo.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

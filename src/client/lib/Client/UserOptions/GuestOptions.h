#ifndef TP_PPROJECT_GUESTOPTIONS_H
#define TP_PPROJECT_GUESTOPTIONS_H

#include <iostream>
#include <memory>

#include "BaseUserOptions.h"

class GuestOptions : public BaseUserOptions {
public:
    ~GuestOptions() override = default;

    // Send message in select chat
    void sendMessage(const Message& message, int globalId,
                     const std::shared_ptr<BaseCallback> callback,
                     std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Update select chat
    void chatUpdate(const ChatUpdates& chatUpdates, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Get list of chats
    void getListChats(const ListChats& listChats, int globalId,
                      const std::shared_ptr<BaseCallback> callback,
                      std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Get select chat room
    void getChatRoom(const ChatRoom& chatRoom, int globalId,
                     const std::shared_ptr<BaseCallback> callback,
                     std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Get messages in select chat
    void getChatMessages(const ChatUpdates& chatUpdates, int globalId,
                         const std::shared_ptr<BaseCallback> callback,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Get last message in chat
    void getLastMessage(const Message& message, int globalId,
                        const std::shared_ptr<BaseCallback> callback,
                        std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Get user 
    void getUser(const UserPreview& user, int globalId,
                 const std::shared_ptr<BaseCallback> callback,
                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Set chat observer
    void setChatObserver(int chatId, const std::shared_ptr<BaseCallback> callback,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Get log
    void getLog(const LogUpdates& logUpdates, int globalId,
                const std::shared_ptr<BaseCallback> callback,
                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Send chat command
    void sendChatCommand(const Message& message, int globalId,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    // Registration new user
    void registration(const UserInfo& authInfo, int globalId,
                      const std::shared_ptr<BaseCallback> callback,
                      std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;
};


#endif

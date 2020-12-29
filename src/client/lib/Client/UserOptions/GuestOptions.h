#ifndef TP_PPROJECT_GUESTOPTIONS_H
#define TP_PPROJECT_GUESTOPTIONS_H

#include <iostream>
#include <memory>

#include "BaseUserOptions.h"

class GuestOptions : public BaseUserOptions {
public:
    ~GuestOptions() override = default;

    void sendMessage(const Message& message, int globalId,
                     const std::shared_ptr<BaseCallback> callback,
                     std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void chatUpdate(const ChatUpdates& chatUpdates, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void getListChats(const ListChats& listChats, int globalId,
                      const std::shared_ptr<BaseCallback> callback,
                      std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void getChatRoom(const ChatRoom& chatRoom, int globalId,
                     const std::shared_ptr<BaseCallback> callback,
                     std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void getChatMessages(const ChatUpdates& chatUpdates, int globalId,
                         const std::shared_ptr<BaseCallback> callback,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void getLastMessage(const Message& message, int globalId,
                        const std::shared_ptr<BaseCallback> callback,
                        std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void getUser(const UserPreview& user, int globalId,
                 const std::shared_ptr<BaseCallback> callback,
                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void setChatObserver(int chatId, const std::shared_ptr<BaseCallback> callback,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void getLog(const LogUpdates& logUpdates, int globalId,
                const std::shared_ptr<BaseCallback> callback,
                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void sendChatCommand(const Message& message, int globalId,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void registration(const UserInfo& authInfo, int globalId,
                      const std::shared_ptr<BaseCallback> callback,
                      std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;
};


#endif

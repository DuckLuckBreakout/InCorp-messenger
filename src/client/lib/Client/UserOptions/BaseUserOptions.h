#ifndef TP_PPROJECT_BASEUSEROPTIONS_H
#define TP_PPROJECT_BASEUSEROPTIONS_H

#include <functional>

#include "ChatObjects/Request.h"
#include "ChatObjects/Message.h"
#include "ChatObjects/Authorization.h"
#include "Commands/CmdCreator/Commands.h"
#include "Client/BaseClient.h"
#include "CallbacksHolder/CallbacksHolder.h"
#include <ChatObjects/ChatUpdates.h>
#include <ChatObjects/ListChats.h>
#include <ChatObjects/ChatRoom.h>
#include <ChatObjects/User.h>
#include <ChatObjects/LogUpdates.h>


class BaseUserOptions {
public:
    virtual ~BaseUserOptions() = default;

    virtual void sendMessage(const Message& message, int globalId,
                             const std::shared_ptr<BaseCallback> callback,
                             std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void authorization(const Authorization& authInfo, int globalId,
                               const std::shared_ptr<BaseCallback> callback,
                               std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void chatUpdate(const ChatUpdates& chatUpdates, int globalId,
                            const std::shared_ptr<BaseCallback> callback,
                            std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void getListChats(const ListChats& listChats, int globalId,
                              const std::shared_ptr<BaseCallback> callback,
                              std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void getChatRoom(const ChatRoom& chatRoom, int globalId,
                             const std::shared_ptr<BaseCallback> callback,
                             std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void getChatMessages(const ChatUpdates& chatUpdates, int globalId,
                                const std::shared_ptr<BaseCallback> callback,
                                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void getLastMessage(const Message& message, int globalId,
                                const std::shared_ptr<BaseCallback> callback,
                                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void getUser(const User& user, int globalId,
                         const std::shared_ptr<BaseCallback> callback,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void setChatObserver(int chatId, const std::shared_ptr<BaseCallback> callback,
                                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void getLog(const LogUpdates& logUpdates, int globalId,
                        const std::shared_ptr<BaseCallback> callback,
                        std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    virtual void sendChatCommand(const Message& message, int globalId,
                                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);
};


#endif

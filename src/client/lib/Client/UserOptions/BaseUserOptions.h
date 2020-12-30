#ifndef TP_PPROJECT_BASEUSEROPTIONS_H
#define TP_PPROJECT_BASEUSEROPTIONS_H

#include <functional>

#include "ChatObjects/Request.h"
#include "ChatObjects/Message.h"
#include "ChatObjects/UserInfo.h"
#include "Commands/CmdCreator/Commands.h"
#include "Client/BaseClient.h"
#include "CallbacksHolder/CallbacksHolder.h"
#include <ChatObjects/ChatUpdates.h>
#include <ChatObjects/ListChats.h>
#include <ChatObjects/ChatRoom.h>
#include <ChatObjects/UserPreview.h>
#include <ChatObjects/LogUpdates.h>


// Abstract user options
class BaseUserOptions {
public:
    virtual ~BaseUserOptions() = default;

    // Send message in select chat
    virtual void sendMessage(const Message& message, int globalId,
                             const std::shared_ptr<BaseCallback> callback,
                             std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Authorization user
    virtual void authorization(const UserInfo& authInfo, int globalId,
                               const std::shared_ptr<BaseCallback> callback,
                               std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Update select chat
    virtual void chatUpdate(const ChatUpdates& chatUpdates, int globalId,
                            const std::shared_ptr<BaseCallback> callback,
                            std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Get list of chats
    virtual void getListChats(const ListChats& listChats, int globalId,
                              const std::shared_ptr<BaseCallback> callback,
                              std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Get select chat room
    virtual void getChatRoom(const ChatRoom& chatRoom, int globalId,
                             const std::shared_ptr<BaseCallback> callback,
                             std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Get messages in select chat
    virtual void getChatMessages(const ChatUpdates& chatUpdates, int globalId,
                                const std::shared_ptr<BaseCallback> callback,
                                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Get last message in chat
    virtual void getLastMessage(const Message& message, int globalId,
                                const std::shared_ptr<BaseCallback> callback,
                                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Get user 
    virtual void getUser(const UserPreview& user, int globalId,
                         const std::shared_ptr<BaseCallback> callback,
                         std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Set chat observer
    virtual void setChatObserver(int chatId, const std::shared_ptr<BaseCallback> callback,
                                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Get log
    virtual void getLog(const LogUpdates& logUpdates, int globalId,
                        const std::shared_ptr<BaseCallback> callback,
                        std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Send message in select chat
    virtual void sendChatCommand(const Message& message, int globalId,
                                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);

    // Registration new user
    virtual void registration(const UserInfo& authInfo, int globalId,
                              const std::shared_ptr<BaseCallback> callback,
                              std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);
};


#endif

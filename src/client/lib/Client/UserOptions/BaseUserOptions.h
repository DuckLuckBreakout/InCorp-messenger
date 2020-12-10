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
};


#endif

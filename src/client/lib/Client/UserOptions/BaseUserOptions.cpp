#include "BaseUserOptions.h"

void BaseUserOptions::sendMessage(const Message& message, int globalId,
                                  const std::shared_ptr<BaseCallback> callback,
                                  std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::SendMessage, callback);
    Request query(Commands::SendMessage, message.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::authorization(const Authorization &authInfo, int globalId,
                                    const std::shared_ptr<BaseCallback> callback,
                                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    int numRequest = callbackHolder->addCallback(Commands::LogIn, callback);
    Request query(Commands::LogIn, authInfo.encode(), globalId, numRequest);
    client->sendMessage(query.encode());
}

void BaseUserOptions::chatUpdate(const ChatUpdates &chatUpdates, int globalId,
                                 const std::shared_ptr<BaseCallback> callback,
                                 std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    callbackHolder->addCallback(Commands::ChatUpdate, callback);
}

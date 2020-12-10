#include "GuestOptions.h"

void GuestOptions::sendMessage(const Message& message, int globalId,
                               const std::shared_ptr<BaseCallback> callback,
                               std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: guest can't send message");
}

#include "ChatObserverCmd.h"

ChatObserverCmd::ChatObserverCmd(int numRequest, const std::optional<std::string>& error,
                             const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void ChatObserverCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> message = std::make_shared<Message>();
    message->decode(body);

    auto func = holder->getCallback(Commands::ChatObserver, numRequest).get();
    (*func)(message, error);
}


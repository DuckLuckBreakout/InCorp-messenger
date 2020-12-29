#include "SendMessageCmd.h"

#include <utility>

SendMessageCmd::SendMessageCmd(int numRequest, const std::optional<std::string>& error,
                               const std::string& body)
        : BaseCmd(numRequest, error, body) {}


void SendMessageCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> message = std::make_shared<Message>();
    message->decode(body);

    auto func = holder->getCallback(Commands::SendMessage, numRequest).get();
    (*func)(message, error);
}

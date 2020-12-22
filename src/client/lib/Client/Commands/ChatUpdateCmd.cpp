#include "ChatUpdateCmd.h"

ChatUpdateCmd::ChatUpdateCmd(int numRequest, const std::optional<std::string>& error,
                             const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void ChatUpdateCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> chatUpdates = std::make_shared<ChatUpdates>();
    chatUpdates->decode(body);

    auto func = holder->getCallback(Commands::SystemUpdate, numRequest).get();
    (*func)(chatUpdates, error);
}

#include "ChatUpdateCmd.h"

#include <utility>

ChatUpdateCmd::ChatUpdateCmd(int numRequest, std::optional<std::string> error,
                             std::string body)
        : BaseCmd(numRequest, std::move(error), std::move(body)) {}

void ChatUpdateCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> chatUpdates = std::make_shared<ChatUpdates>();
    chatUpdates->decode(body);

    auto func = holder->getCallback(Commands::ChatUpdate, numRequest).get();
    (*func)(chatUpdates);
}

#include "GetChatMessagesCmd.h"

GetChatMessagesCmd::GetChatMessagesCmd(int numRequest, const std::optional<std::string>& error,
                                       const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void GetChatMessagesCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> chatUpdates = std::make_shared<ChatUpdates>();
    chatUpdates->decode(body);

    auto func = holder->getCallback(Commands::GetMessagesInChat, numRequest).get();
    (*func)(chatUpdates, error);
}


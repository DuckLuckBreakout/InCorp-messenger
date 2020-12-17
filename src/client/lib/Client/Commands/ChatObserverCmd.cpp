#include "ChatObserverCmd.h"

ChatObserverCmd::ChatObserverCmd(int numRequest, const std::optional<std::string>& error,
                             const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void ChatObserverCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    Parser parser;
    parser.setJson(body);

    std::shared_ptr<BaseObject> data;
    ChatAction action;
    action.decode(body);

    if (action.chatAction == 1) {
        data = std::make_shared<Message>();
        data->decode(body);
        action.data = data;
    }
    else if (action.chatAction == 2) {
        data = std::make_shared<Checked>();
        data->decode(body);
        action.data = data;
    }

    auto func = holder->getCallback(Commands::ChatObserver, numRequest).get();
    (*func)(std::make_shared<ChatAction>(action), error);
}


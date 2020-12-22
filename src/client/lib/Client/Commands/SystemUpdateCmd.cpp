#include "SystemUpdateCmd.h"

SystemUpdateCmd::SystemUpdateCmd(int numRequest, const std::optional<std::string>& error,
                                 const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void SystemUpdateCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    Parser parser;
    parser.setJson(body);

    std::shared_ptr<BaseObject> data;
    ChatAction action;
    action.decode(body);

    if (action.chatAction == 1) {
        data = std::make_shared<ChatItem>();
        data->decode(body);
        action.data = data;
    }

    auto func = holder->getCallback(Commands::SystemUpdate, numRequest).get();
    (*func)(std::make_shared<ChatAction>(action), error);
}

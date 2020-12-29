#include "GetListChatsCmd.h"

GetListChatsCmd::GetListChatsCmd(int numRequest, const std::optional<std::string>& error,
                                 const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void GetListChatsCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> listChats = std::make_shared<ListChats>();
    listChats->decode(body);

    auto func = holder->getCallback(Commands::GetListOfChats, numRequest).get();
    (*func)(listChats, error);
}

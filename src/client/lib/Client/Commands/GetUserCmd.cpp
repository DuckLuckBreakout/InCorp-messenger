#include "GetUserCmd.h"

GetUserCmd::GetUserCmd(int numRequest, const std::optional<std::string>& error,
                       const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void GetUserCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> listChats = std::make_shared<UserPreview>();
    listChats->decode(body);

    auto func = holder->getCallback(Commands::GetUserData, numRequest).get();
    (*func)(listChats, error);
}


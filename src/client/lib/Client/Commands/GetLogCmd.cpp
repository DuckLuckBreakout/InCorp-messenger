#include "GetLogCmd.h"

GetLogCmd::GetLogCmd(int numRequest, const std::optional<std::string>& error,
                     const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void GetLogCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> logs = std::make_shared<LogUpdates>();
    logs->decode(body);

    std::cerr << numRequest << std::endl;
    auto func = holder->getCallback(Commands::GetLog, numRequest).get();
    (*func)(logs, error);
}



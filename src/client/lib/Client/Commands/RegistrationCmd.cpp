#include "RegistrationCmd.h"

RegistrationCmd::RegistrationCmd(int numRequest, const std::optional<std::string>& error,
                                   const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void RegistrationCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> authInfo = std::make_shared<Authorization>();

    if (!error)
        authInfo->decode(body);

    auto func = holder->getCallback(Commands::RegistrationUser, numRequest).get();
    (*func)(authInfo, error);
}

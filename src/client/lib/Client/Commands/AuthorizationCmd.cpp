#include "AuthorizationCmd.h"

AuthorizationCmd::AuthorizationCmd(int numRequest, const std::optional<std::string>& error,
                                   const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void AuthorizationCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> authInfo = std::make_shared<Authorization>();

    if (!error)
        authInfo->decode(body);

    auto func = holder->getCallback(Commands::LogIn, numRequest).get();
    (*func)(authInfo, error);
}

#include "AuthorizationCmd.h"

#include <utility>

AuthorizationCmd::AuthorizationCmd(int numRequest, std::optional<std::string> error,
                                   std::string body)
        : BaseCmd(numRequest, std::move(error), std::move(body)) {}

void AuthorizationCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> authInfo = std::make_shared<Authorization>();
    authInfo->decode(body);

    auto func = holder->getCallback(Commands::LogIn, numRequest).get();
    (*func)(authInfo);
}

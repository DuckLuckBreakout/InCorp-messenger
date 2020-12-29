#include "EmployeeOptions.h"

void EmployeeOptions::getLog(const LogUpdates &logUpdates, int globalId, const std::shared_ptr<BaseCallback> callback,
                             std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: employee can't get server log");
}

void EmployeeOptions::registration(const UserInfo &authInfo, int globalId, const std::shared_ptr<BaseCallback> callback,
                                   std::shared_ptr<BaseClient> client,
                                   std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: employee can't register new user");
}

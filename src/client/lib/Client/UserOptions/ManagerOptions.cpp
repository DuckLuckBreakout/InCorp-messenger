#include "ManagerOptions.h"

void ManagerOptions::getLog(const LogUpdates &logUpdates, int globalId, const std::shared_ptr<BaseCallback> callback,
                            std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) {
    throw std::runtime_error("exception: manager can't get server log");
}

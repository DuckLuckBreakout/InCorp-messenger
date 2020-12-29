#ifndef TP_PPROJECT_MANAGEROPTIONS_H
#define TP_PPROJECT_MANAGEROPTIONS_H

#include <iostream>

#include "BaseUserOptions.h"

class ManagerOptions : public BaseUserOptions {
public:
    ~ManagerOptions() override = default;

    void getLog(const LogUpdates& logUpdates, int globalId,
                const std::shared_ptr<BaseCallback> callback,
                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

};


#endif

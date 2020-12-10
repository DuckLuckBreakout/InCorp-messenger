#ifndef TP_PPROJECT_GUESTOPTIONS_H
#define TP_PPROJECT_GUESTOPTIONS_H

#include <iostream>
#include <memory>

#include "BaseUserOptions.h"

class GuestOptions : public BaseUserOptions {
public:
    ~GuestOptions() override = default;

    virtual void sendMessage(const Message& message, int globalId,
                             const std::shared_ptr<BaseCallback> callback,
                             std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder);
};


#endif

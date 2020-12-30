#ifndef APPLICATION_SENDMESSAGECMD_H
#define APPLICATION_SENDMESSAGECMD_H

#include <iostream>

#include "BaseCmd.h"
#include "ChatObjects/Message.h"
#include "Commands/CmdCreator/Commands.h"


// Command for send message
class SendMessageCmd : public BaseCmd {
public:
    ~SendMessageCmd() override = default;

    SendMessageCmd(int numRequest, const std::optional<std::string>& error,
                   const std::string&  body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_SENDMESSAGECMD_H

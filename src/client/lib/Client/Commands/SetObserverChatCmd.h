#ifndef APPLICATION_SETOBSERVERCHATCMD_H
#define APPLICATION_SETOBSERVERCHATCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "ChatObjects/Message.h"
#include "Commands/CmdCreator/Commands.h"


class SetObserverChatCmd : public BaseCmd {
public:
    ~SetObserverChatCmd() override = default;

    SetObserverChatCmd(int numRequest, const std::optional<std::string>& error,
                       const std::string&  body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_SETOBSERVERCHATCMD_H

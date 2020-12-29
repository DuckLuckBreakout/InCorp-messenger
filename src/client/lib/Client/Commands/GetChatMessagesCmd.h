#ifndef APPLICATION_GETCHATMESSAGESCMD_H
#define APPLICATION_GETCHATMESSAGESCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatUpdates.h"


class GetChatMessagesCmd : public BaseCmd {
public:
    ~GetChatMessagesCmd() override = default;

    GetChatMessagesCmd(int numRequest, const std::optional<std::string>& error,
                       const std::string& body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_GETCHATMESSAGESCMD_H

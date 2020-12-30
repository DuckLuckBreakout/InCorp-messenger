#ifndef APPLICATION_GETCHATMESSAGESCMD_H
#define APPLICATION_GETCHATMESSAGESCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatUpdates.h"


// Command for get message in select chat
class GetChatMessagesCmd : public BaseCmd {
public:
    ~GetChatMessagesCmd() override = default;

    GetChatMessagesCmd(int numRequest, const std::optional<std::string>& error,
                       const std::string& body);

	// Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_GETCHATMESSAGESCMD_H

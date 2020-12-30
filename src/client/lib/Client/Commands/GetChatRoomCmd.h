#ifndef APPLICATION_GETCHATROOMCMD_H
#define APPLICATION_GETCHATROOMCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatRoom.h"


// Command for get chat room
class GetChatRoomCmd : public BaseCmd {
public:
    ~GetChatRoomCmd() override = default;

    GetChatRoomCmd(int numRequest, const std::optional<std::string>& error,
                   const std::string&  body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_GETCHATROOMCMD_H

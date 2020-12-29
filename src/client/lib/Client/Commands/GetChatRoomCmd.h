#ifndef APPLICATION_GETCHATROOMCMD_H
#define APPLICATION_GETCHATROOMCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatRoom.h"


class GetChatRoomCmd : public BaseCmd {
public:
    ~GetChatRoomCmd() override = default;

    GetChatRoomCmd(int numRequest, const std::optional<std::string>& error,
                   const std::string&  body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_GETCHATROOMCMD_H

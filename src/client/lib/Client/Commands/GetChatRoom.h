#ifndef APPLICATION_GETCHATROOM_H
#define APPLICATION_GETCHATROOM_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatRoom.h"


class GetChatRoom : public BaseCmd {
public:
    ~GetChatRoom() override = default;

    GetChatRoom(int numRequest, const std::optional<std::string>& error,
                const std::string&  body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_GETCHATROOM_H

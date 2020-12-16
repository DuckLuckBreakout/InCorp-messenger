#ifndef APPLICATION_GETCHATMESSAGES_H
#define APPLICATION_GETCHATMESSAGES_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatUpdates.h"


class GetChatMessages : public BaseCmd {
public:
    ~GetChatMessages() override = default;

    GetChatMessages(int numRequest, const std::optional<std::string>& error,
                     const std::string& body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_GETCHATMESSAGES_H

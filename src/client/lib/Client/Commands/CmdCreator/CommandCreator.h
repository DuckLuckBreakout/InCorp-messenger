#ifndef APPLICATION_COMMANDCREATOR_H
#define APPLICATION_COMMANDCREATOR_H

#include <memory>

#include "Commands/BaseCmd.h"
#include "Commands/SendMessageCmd.h"
#include "Commands.h"
#include "Commands/AuthorizationCmd.h"
#include "Commands/ChatUpdateCmd.h"
#include "Commands/GetListChats.h"
#include "Commands/GetChatRoom.h"
#include "Commands/GetChatMessages.h"
#include "Commands/GetLastMessageCmd.h"
#include "Commands/GetUserCmd.h"
#include "Commands/ChatObserverCmd.h"
#include "Commands/GetLogCmd.h"
#include "Commands/SystemUpdateCmd.h"


class CommandCreator {
public:
    static std::shared_ptr<BaseCmd> createCommand(int command, const std::optional<std::string>& error,
                                                  const std::string& body, int numRequest);
};


#endif //APPLICATION_COMMANDCREATOR_H

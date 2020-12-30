#ifndef APPLICATION_COMMANDCREATOR_H
#define APPLICATION_COMMANDCREATOR_H

#include <memory>

#include "Commands/BaseCmd.h"
#include "Commands/SendMessageCmd.h"
#include "Commands.h"
#include "Commands/AuthorizationCmd.h"
#include "Commands/ChatUpdateCmd.h"
#include "Commands/GetListChatsCmd.h"
#include "Commands/GetChatRoomCmd.h"
#include "Commands/GetChatMessagesCmd.h"
#include "Commands/GetLastMessageCmd.h"
#include "Commands/GetUserCmd.h"
#include "Commands/ChatObserverCmd.h"
#include "Commands/GetLogCmd.h"
#include "Commands/SystemUpdateCmd.h"
#include "Commands/RegistrationCmd.h"


// Command creator for creating command by system number of command
class CommandCreator {
public:
	// Create new command
    static std::shared_ptr<BaseCmd> createCommand(int command, const std::optional<std::string>& error,
                                                  const std::string& body, int numRequest);
};


#endif //APPLICATION_COMMANDCREATOR_H

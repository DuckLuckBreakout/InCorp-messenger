#ifndef APPLICATION_CHATUPDATECMD_H
#define APPLICATION_CHATUPDATECMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatUpdates.h"


// Command for chat update select chat
class ChatUpdateCmd : public BaseCmd {
public:
    ~ChatUpdateCmd() override = default;

    ChatUpdateCmd(int numRequest, const std::optional<std::string>& error,
                  const std::string&  body);

	// Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_CHATUPDATECMD_H

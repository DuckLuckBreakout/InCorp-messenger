#ifndef APPLICATION_SYSTEMUPDATECMD_H
#define APPLICATION_SYSTEMUPDATECMD_H

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatUpdates.h"
#include "ChatObjects/ChatItem.h"
#include "ChatObjects/ChatAction.h"


// Command for system update from server
class SystemUpdateCmd : public BaseCmd {
public:
    ~SystemUpdateCmd() override = default;

    SystemUpdateCmd(int numRequest, const std::optional<std::string>& error,
                    const std::string&  body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_SYSTEMUPDATECMD_H

#ifndef APPLICATION_CHATOBSERVERCMD_H
#define APPLICATION_CHATOBSERVERCMD_H

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ChatUpdates.h"
#include "ChatObjects/Checked.h"
#include "ChatObjects/ChatAction.h"


class ChatObserverCmd : public BaseCmd {
public:
    ~ChatObserverCmd() override = default;

    ChatObserverCmd(int numRequest, const std::optional<std::string>& error,
                    const std::string&  body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_CHATOBSERVERCMD_H

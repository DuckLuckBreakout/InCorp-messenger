#ifndef APPLICATION_GETLASTMESSAGECMD_H
#define APPLICATION_GETLASTMESSAGECMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/Message.h"


class GetLastMessageCmd : public BaseCmd {
public:
    ~GetLastMessageCmd() override = default;

    GetLastMessageCmd(int numRequest, const std::optional<std::string>& error,
                      const std::string&  body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_GETLASTMESSAGECMD_H

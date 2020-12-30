#ifndef APPLICATION_AUTHORIZATIONCMD_H
#define APPLICATION_AUTHORIZATIONCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/UserInfo.h"


// Command for authorization user
class AuthorizationCmd : public BaseCmd {
public:
    ~AuthorizationCmd() override = default;

    AuthorizationCmd(int numRequest, const std::optional<std::string>& error,
                     const std::string& body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_AUTHORIZATIONCMD_H

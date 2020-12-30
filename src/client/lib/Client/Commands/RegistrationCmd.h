#ifndef APPLICATION_REGISTRATIONCMD_H
#define APPLICATION_REGISTRATIONCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/UserInfo.h"


// Command for registration
class RegistrationCmd : public BaseCmd {
public:
    ~RegistrationCmd() override = default;

    RegistrationCmd(int numRequest, const std::optional<std::string>& error,
                     const std::string& body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};



#endif //APPLICATION_REGISTRATIONCMD_H

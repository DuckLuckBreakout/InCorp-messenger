#ifndef APPLICATION_AUTHORIZATIONCMD_H
#define APPLICATION_AUTHORIZATIONCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/Authorization.h"


class AuthorizationCmd : public BaseCmd {
public:
    ~AuthorizationCmd() override = default;

    AuthorizationCmd(int numRequest, std::optional<std::string> error,
                     std::string  body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_AUTHORIZATIONCMD_H

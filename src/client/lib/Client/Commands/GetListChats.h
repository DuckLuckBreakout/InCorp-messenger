#ifndef APPLICATION_GETLISTCHATS_H
#define APPLICATION_GETLISTCHATS_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ListChats.h"


class GetListChats : public BaseCmd {
public:
    ~GetListChats() override = default;

    GetListChats(int numRequest, const std::optional<std::string>& error,
                 const std::string& body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_GETLISTCHATS_H
